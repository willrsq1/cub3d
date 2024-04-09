/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:12:02 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 18:21:16 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static double	get_dist(t_cube *cube, t_player *player, double x, double y);
static void		get_exact_coords(double *x, double *y, t_cube *cube);
static void		ft_texture(t_player *player, double x, double y, t_cube *cube);
static void		draw_wall(double dist, t_cube *cube, int x);

void	ft_raycasting(t_cube *cube, t_player *player)
{
	double	distance;
	double	angle;
	int		pixel_column;

	fix_angle(&player->direction);
	pixel_column = 0;
	angle = player->direction + (player->fov / 2);
	while (pixel_column <= WIN_WIDTH)
	{
		angle -= player->fov / WIN_WIDTH;
		player->vector_x = cosf(angle) * 0.01;
		player->vector_y = sinf(angle) * 0.01;
		distance = get_dist(cube, player, player->x, player->y);
		distance *= cosf(player->direction - angle);
		draw_wall(distance, cube, pixel_column);
		pixel_column++;
	}
}

static double	get_dist(t_cube *cube, t_player *player, double x, double y)
{
	double	distance;

	while (ft_valid_pos(cube, x, y) < 1)
	{
		x += player->vector_x;
		y += player->vector_y;
	}
	get_exact_coords(&x, &y, cube);
	ft_texture(player, x, y, cube);
	distance = ft_distance(x, y, player->x, player->y);
	return (distance);
}

static void	get_exact_coords(double *x, double *y, t_cube *cube)
{
	while (ft_valid_pos(cube, *x, *y) > 0)
	{
		*x -= cube->player.vector_x * (RESOLUTION * 100);
		*y -= cube->player.vector_y * (RESOLUTION * 100);
	}
	while (ft_valid_pos(cube, *x, *y) < 1)
	{
		*x += cube->player.vector_x * (RESOLUTION * 10);
		*y += cube->player.vector_y * (RESOLUTION * 10);
	}
	while (ft_valid_pos(cube, *x, *y) > 0)
	{
		*x -= cube->player.vector_x * RESOLUTION;
		*y -= cube->player.vector_y * RESOLUTION;
	}
	*x += cube->player.vector_x * RESOLUTION;
	*y += cube->player.vector_y * RESOLUTION;
}

static void	ft_texture(t_player *player, double x, double y, t_cube *cube)
{
	player->x_wall = fabs((int)x - x);
	if (abs((int)x) != abs((int)(x - player->vector_x * RESOLUTION)))
		player->x_wall = fabs((int)y - y);
	if (fabs((int)x - x) >= fabs((int)y - y))
	{
		cube->id = EAST;
		if (abs((int)x) != abs((int)(x - player->vector_x * RESOLUTION)))
			cube->id = NORTH;
	}
	else
	{
		cube->id = WEST;
		if (abs((int)x) != abs((int)(x - player->vector_x * RESOLUTION)))
			cube->id = SOUTH;
	}
}

static void	draw_wall(double dist, t_cube *cube, int x)
{
	int		wall_size;
	int		half_of_wall_size;
	int		y;

	if (dist < 1)
		dist = 1;
	wall_size = WIN_HEIGHT / dist;
	wall_size /= (float)WIN_HEIGHT / (float)WIN_WIDTH * cube->player.fov;
	half_of_wall_size = wall_size / 2;
	if (half_of_wall_size > WIN_HEIGHT / 2)
		half_of_wall_size = WIN_HEIGHT / 2;
	y = 0;
	while (y < WIN_HEIGHT / 2 - half_of_wall_size)
	{
		ft_pixel(cube->img, x, y, cube->ceiling_color);
		y++;
	}
	while (y <= WIN_HEIGHT / 2 + half_of_wall_size - 1)
	{
		ft_wall_pixel(cube, x, y, wall_size);
		y++;
	}
	while (y <= WIN_HEIGHT)
		ft_pixel(cube->img, x, y++, cube->floor_color);
}
