/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:43:57 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:28 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static double	ft_check_for_closed_door(t_cube *cube);
static double	ft_check_for_opened_door(t_cube *cube);

void	ft_doors(int key, t_cube *cube)
{
	double	i;

	i = ft_check_for_closed_door(cube);
	cube->door_message = 0;
	if (i)
	{
		cube->door_message = 1;
		if (key == 120)
		{
			cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
				* i)][(int)(cube->player.y + sinf(cube->player.angle) \
				* i)] = OPENED_DOOR;
			return ;
		}
	}
	i = ft_check_for_opened_door(cube);
	if (i)
	{
		cube->door_message = 1;
		if (key == 120)
			cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
				* i)][(int)(cube->player.y + sinf(cube->player.angle) \
				* i)] = CLOSED_DOOR;
	}
}

static double	ft_check_for_closed_door(t_cube *cube)
{
	double	i;

	i = 0.01;
	while (i < 2)
	{
		if (ft_valid_pos_bonus(cube, cube->player.x + cosf(cube->player.angle) \
			* i, cube->player.y + sinf(cube->player.angle) \
			* i) == CLOSED_DOOR)
			return (i);
		i += 0.01;
	}
	return (0);
}

static double	ft_check_for_opened_door(t_cube *cube)
{
	double	i;

	i = 0.01;
	if (cube->map[(int)cube->player.x][(int)cube->player.y] == OPENED_DOOR)
		return (0);
	while (i < 2)
	{
		if (ft_valid_pos_bonus(cube, cube->player.x + cosf(cube->player.angle) \
			* i, cube->player.y + sinf(cube->player.angle) \
			* i) == OPENED_DOOR)
			return (i);
		i += 0.01;
	}
	return (0);
}

void	print_s(int x, int y, t_cube *cube, int color)
{
	int	i;

	i = 0;
	while (i++ < 26)
	{
		ft_pixel(cube->img, x + i, y, color);
		ft_pixel(cube->img, x + i, y + 1, color);
		ft_pixel(cube->img, x + i, y + 21, color);
		ft_pixel(cube->img, x + i, y + 22, color);
		ft_pixel(cube->img, x + i, y + 40, color);
		ft_pixel(cube->img, x + i, y + 41, color);
	}
	while (i++ < 66)
	{
		if (i < 46)
		{
			ft_pixel(cube->img, x, i + y - 26, color);
			ft_pixel(cube->img, x + 1, i + y - 25, color);
		}
		else
		{
			ft_pixel(cube->img, x + 25, i + y - 26, color);
			ft_pixel(cube->img, x + 26, i + y - 25, color);
		}
	}
}

void	print_x(int x, int y, t_cube *cube, int color)
{
	int	i;

	i = 0;
	while (i++ < 20)
	{
		ft_pixel(cube->img, x + i, y, color);
		ft_pixel(cube->img, x + i, y + 1, color);
		ft_pixel(cube->img, x + i, y + 2, color);
		ft_pixel(cube->img, x + i, y + 3, color);
		ft_pixel(cube->img, x + i, y + 4, color);
		ft_pixel(cube->img, x + i, y + 5, color);
		ft_pixel(cube->img, x + 20 - i, y, color);
		ft_pixel(cube->img, x + 20 - i, y + 1, color);
		ft_pixel(cube->img, x + 20 - i, y + 2, color);
		ft_pixel(cube->img, x + 20 - i, y + 3, color);
		ft_pixel(cube->img, x + 20 - i, y + 4, color);
		ft_pixel(cube->img, x + 20 - i, y + 5, color);
		y += 2;
	}
}
