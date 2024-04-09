/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:16:33 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/14 21:54:22 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_propagate_pollution(t_cube *cube, int **map);
static void	ft_win_lose(t_cube *cube, int **map);
static void	win_lose_screen(t_cube *cube, bool has_zeros, bool has_enemies);
static void	ft_create_new_enemy(t_cube *cube, int **map, int x, int y);

void	ft_pollution(t_cube *cube, int **map)
{
	time_t	time;
	int		x;
	int		y;

	if (!cube->game_was_won)
		ft_win_lose(cube, cube->map);
	time = ft_time() - cube->start;
	if (time < SPAWN_TIME)
		return ;
	cube->start = ft_time();
	ft_propagate_pollution(cube, map);
	x = -1;
	while (++x < cube->map_lenght)
	{
		y = 0;
		while (y < cube->map_width)
		{
			if (map[x][y] == NEW_ENEMY || map[x][y] == HURT_ENEMY)
				map[x][y] = ENEMY;
			y++;
		}
	}
}

static void	ft_propagate_pollution(t_cube *cube, int **map)
{
	int		x;
	int		y;

	x = 0;
	while (x < cube->map_lenght)
	{
		y = 0;
		while (y < cube->map_width)
		{
			if (map[x][y] == ENEMY)
			{
				ft_create_new_enemy(cube, map, x - 1, y);
				ft_create_new_enemy(cube, map, x, y - 1);
				ft_create_new_enemy(cube, map, x + 1, y);
				ft_create_new_enemy(cube, map, x, y + 1);
			}
			y++;
		}
		x++;
	}
}

static void	ft_win_lose(t_cube *cube, int **map)
{
	int		x;
	int		y;
	bool	has_zeros;
	bool	has_enemies;

	x = -1;
	has_enemies = 0;
	has_zeros = 0;
	while (++x < cube->map_lenght)
	{
		y = 0;
		while (y < cube->map_width)
		{
			if (map[x][y] == 0 && \
				(x != (int)cube->player.x || y != (int)cube->player.y))
				has_zeros = 1;
			if (map[x][y] <= ENEMY && \
				(x != (int)cube->player.x || y != (int)cube->player.y))
				has_enemies = 1;
			y++;
		}
	}
	win_lose_screen(cube, has_zeros, has_enemies);
}

static void	win_lose_screen(t_cube *cube, bool has_zeros, bool has_enemies)
{
	if (!has_zeros)
	{
		cube->lost = 1;
		ft_create_image(cube);
		put_my_img_to_img(0, 0, cube->sprites[LOST], cube->img);
		ft_destroy_image(cube);
	}
	if (!has_enemies)
	{
		cube->win = 1;
		ft_create_image(cube);
		put_my_img_to_img(0, 0, cube->sprites[WIN], cube->img);
		ft_destroy_image(cube);
	}
}

static void	ft_create_new_enemy(t_cube *cube, int **map, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if ((map[x][y] == 0 || map[x][y] == OPENED_DOOR) \
		&& !(x == (int)cube->player.x && y == (int)cube->player.y))
		map[x][y] = NEW_ENEMY;
	return ;
}
