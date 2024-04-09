/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:58:38 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 09:54:53 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	**map_allocation(int fd, t_cube *cube);
static void	map_size(int *nb_of_lines, int *max_lenght, int fd, t_cube *cube);
static int	**address_allocation(int **map, int nb_of_lines, int max_lenght);
static void	fill_map(int fd, t_cube *cube, int x, int y);

int	**ft_map(char *path, t_cube *cube)
{
	int		**map;

	if (ft_format(path) == 1)
		ft_error("Not a .cub file", NULL, NULL, cube);
	cube->fd = open(path, O_RDONLY);
	if (cube->fd == -1)
	{
		perror(path);
		exit(1);
	}
	ft_textures_and_colors(cube, cube->fd, NULL, 0);
	map = map_allocation(cube->fd, cube);
	cube->map = map;
	cube->fd = open(path, O_RDONLY);
	if (cube->fd == -1)
	{
		perror(path);
		ft_free_exit(cube);
	}
	skip_elements(cube->fd, cube);
	fill_map(cube->fd, cube, 0, 0);
	close(cube->fd);
	cube->fd = -1;
	return (map);
}

static int	**map_allocation(int fd, t_cube *cube)
{
	int		**map;
	int		nb_of_lines;
	int		max_lenght;

	nb_of_lines = 0;
	max_lenght = 0;
	map = NULL;
	map_size(&nb_of_lines, &max_lenght, fd, cube);
	cube->fd = -1;
	close(fd);
	cube->map_lenght = nb_of_lines;
	cube->map_width = max_lenght;
	map = address_allocation(map, nb_of_lines, max_lenght);
	if (!map)
	{
		write(2, "Error: Allocation of map.\n", 26);
		close(fd);
		exit(1);
	}
	return (map);
}

static void	map_size(int *nb_of_lines, int *max_lenght, int fd, t_cube *cube)
{
	char	*buff;
	int		y;

	while (1 && *nb_of_lines < INT_MAX)
	{
		y = 0;
		buff = get_next_line(fd);
		if (!buff)
			break ;
		while (buff[y] && buff[y] != '\n')
		{
			if (!(buff[y] == 'N' || buff[y] == 'S' || buff[y] == 'E' || \
				buff[y] == 'W' || buff[y] == '0' || buff[y] == '1' || \
				buff[y] == ' '))
				ft_error("Unallowed character in lign: ", buff, buff, cube);
			y++;
		}
		if (y > *max_lenght)
			*max_lenght = y;
		if (y)
			*nb_of_lines += 1;
		free(buff);
	}
}

static int	**address_allocation(int **map, int nb_of_lines, int max_lenght)
{
	int		y;

	map = ft_calloc(sizeof(int *) * nb_of_lines + 5, 1);
	if (!map)
		return (NULL);
	y = -1;
	while (++y < nb_of_lines)
	{
		map[y] = ft_calloc(sizeof(int) * max_lenght + 5, 1);
		if (!map[y])
		{
			while (--y >= 0)
				free(map[y]);
			return (NULL);
		}
	}
	return (map);
}

static void	fill_map(int fd, t_cube *cube, int x, int y)
{
	char	*buff;

	while (1 && x < INT_MAX)
	{
		y = 0;
		buff = get_next_line(fd);
		if (!buff)
			break ;
		while (buff[y] && buff[y] != '\n')
		{
			cube->map[x][y] = ft_atoi_cube(buff[y]);
			y++;
		}
		while (y <= cube->map_width && y != 0)
			cube->map[x][y++] = END;
		if (y == 0)
			ft_empty_line_in_map(cube, buff, fd, x--);
		else
			free(buff);
		x++;
	}
	cube->map_lenght = x;
}
