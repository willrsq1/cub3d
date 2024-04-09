/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_back_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:59:35 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:28 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static double	get_dist_enemy_back(t_cube *cube, t_player *player, \
	double x, double y);
static void		get_exact_coords_enemy_back(double *x, double *y, t_cube *cube);
static void		ft_recursive_drawing(t_cube *cube, double *x, double *y);

void	draw_enemy_back(t_cube *cube, t_player *player, double angle, int x)
{
	double	distance;

	player->vector_x = cosf(angle) * 0.01;
	player->vector_y = sinf(angle) * 0.01;
	distance = get_dist_enemy_back(cube, player, player->x, player->y);
	if (distance == -1)
		return ;
	distance *= cosf(player->angle - angle) * player->fov;
	draw_column_enemy(distance, cube, x);
}

static double	get_dist_enemy_back(t_cube *cube, t_player *player, \
	double x, double y)
{
	double	distance;
	int		return_value;

	while (1)
	{
		return_value = ft_valid_pos_enemy(cube, x, y);
		if (return_value == END)
			return (-1);
		if (return_value <= ENEMY)
			break ;
		x += player->vector_x;
		y += player->vector_y;
	}
	get_exact_coords_enemy_back(&x, &y, cube);
	cube->id = cube->map[(int)x][(int)y];
	player->x_wall = fabs((int)x - x);
	if (abs((int)x) != abs((int)(x + player->vector_x * RESOLUTION)))
		player->x_wall = fabs((int)y - y);
	distance = ft_distance(x, y, player->x, player->y);
	return (distance);
}

static void	get_exact_coords_enemy_back(double *x, double *y, t_cube *cube)
{
	while (ft_valid_pos_enemy(cube, *x, *y) <= ENEMY)
	{
		*x += cube->player.vector_x;
		*y += cube->player.vector_y;
	}
	while (ft_valid_pos_enemy(cube, *x, *y) > ENEMY)
	{
		*x -= cube->player.vector_x * (RESOLUTION * 100);
		*y -= cube->player.vector_y * (RESOLUTION * 100);
	}
	while (ft_valid_pos_enemy(cube, *x, *y) <= ENEMY)
	{
		*x += cube->player.vector_x * (RESOLUTION * 10);
		*y += cube->player.vector_y * (RESOLUTION * 10);
	}
	while (ft_valid_pos_enemy(cube, *x, *y) > ENEMY)
	{
		*x -= cube->player.vector_x * RESOLUTION;
		*y -= cube->player.vector_y * RESOLUTION;
	}
	ft_recursive_drawing(cube, x, y);
}

static void	ft_recursive_drawing(t_cube *cube, double *x, double *y)
{
	double	save_x;
	double	save_y;

	save_x = cube->player.x;
	save_y = cube->player.y;
	if (ft_valid_pos_enemy(cube, *x + cube->player.vector_x, \
		*y + cube->player.vector_y) != END && ((int)*x != (int)(*x + \
		cube->player.vector_x) && (int)*y != (int)(*y + cube->player.vector_y)))
	{
		cube->player.x = *x + cube->player.vector_x;
		cube->player.y = *y + cube->player.vector_y;
		draw_enemy_back(cube, &cube->player, cube->angle, cube->fd);
	}
	cube->player.x = save_x;
	cube->player.y = save_y;
}
