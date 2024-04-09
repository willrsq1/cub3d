/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:56:12 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 09:22:02 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static char	*ft_get_texture(char *texture, t_cube *cube, char *s);
static char	*check_error_element(char *s, t_cube *cube);

void	ft_textures_and_colors(t_cube *cube, int fd, char *s, int count)
{
	while (count != 6)
	{
		s = get_next_line(fd);
		if (!s && write(2, "Incomplete .cub file: Missing an id.\n", 38))
			ft_free_exit(cube);
		if (s[0] == 'N' && (s[1] == 'O' || s[1] == ' ') && ++count)
			cube->text_north = ft_get_texture(cube->text_north, cube, s);
		else if (s[0] == 'S' && (s[1] == 'O' || s[1] == ' ') && ++count)
			cube->text_south = ft_get_texture(cube->text_south, cube, s);
		else if (s[0] == 'W' && (s[1] == 'E' || s[1] == ' ') && ++count)
			cube->text_west = ft_get_texture(cube->text_west, cube, s);
		else if (s[0] == 'E' && (s[1] == 'A' || s[1] == ' ') && ++count)
			cube->text_east = ft_get_texture(cube->text_east, cube, s);
		else if (s[0] == 'C' && s[1] == ' ' && ++count)
			cube->ceiling_color = ft_get_color(cube->ceiling_color, cube, s);
		else if (s[0] == 'F' && s[1] == ' ' && ++count)
			cube->floor_color = ft_get_color(cube->floor_color, cube, s);
		else if (s[0] != '\n' && count)
			ft_error("Unallowed lign: ", s, s, cube);
		free(s);
	}
}

static char	*ft_get_texture(char *texture, t_cube *cube, char *s)
{
	int	fd;

	if (texture)
		ft_error("This element has multiple definitions: ", s, s, cube);
	s[ft_strlen(s) - 1] = '\0';
	texture = check_error_element(s, cube);
	fd = open(texture, O_RDONLY);
	if (fd != -1)
		close(fd);
	if (fd == -1)
	{
		perror(texture);
		free(texture);
		free(s);
		ft_free_exit(cube);
	}
	return (texture);
}

static char	*check_error_element(char *s, t_cube *cube)
{
	int		i;
	char	*texture;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	if (!s[i] || i > 2)
		ft_error("This line is not formated properly ", s, s, cube);
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i] || s[i] == '\n')
		ft_error("This element doesn't contain a file: ", s, s, cube);
	texture = ft_strdup(&s[i]);
	if (!texture)
	{
		free(s);
		ft_free_exit(cube);
	}
	return (texture);
}

void	ft_error(char *s1, char *s2, char *s3, t_cube *cube)
{
	write(2, "error: ", 7);
	if (s1)
		write(2, s1, ft_strlen(s1));
	if (s2)
		write(2, s2, ft_strlen(s2));
	if (s3)
		free(s3);
	write(2, "\n", 1);
	ft_free_exit(cube);
}
