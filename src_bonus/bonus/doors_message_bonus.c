/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:25:32 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/10 22:46:00 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	print_p(int x, int y, t_cube *cube, int color);
static void	print_r(int x, int y, t_cube *cube, int color);
static void	print_r_part2(int x, int y, t_cube *cube, int color);
static void	print_e(int x, int y, t_cube *cube, int color);

void	print_door_message(t_cube *cube)
{
	int		x;
	int		y;
	int		increment;

	x = WIN_WIDTH / 2.9;
	y = WIN_HEIGHT * 0.8;
	increment = WIN_WIDTH / 33;
	print_p(x, y, cube, BLACK);
	print_r(x + increment, y, cube, BLACK);
	print_e(x + increment * 2, y, cube, BLACK);
	print_s(x + increment * 3, y, cube, BLACK);
	print_s(x + increment * 4, y, cube, BLACK);
	print_x(x + increment * 6, y, cube, BLACK);
}

static void	print_p(int x, int y, t_cube *cube, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 26)
	{
		ft_pixel(cube->img, x + i, y, color);
		ft_pixel(cube->img, x + i, y + 1, color);
		ft_pixel(cube->img, x + i, y + 21, color);
		ft_pixel(cube->img, x + i, y + 22, color);
	}
	while (j++ < 40)
	{
		ft_pixel(cube->img, x, j + y, color);
		ft_pixel(cube->img, x + 1, j + y + 1, color);
		if (j < 21)
			ft_pixel(cube->img, x + i + 1, j + y, color);
		if (j < 21)
			ft_pixel(cube->img, x + i, j + y, color);
	}
}

static void	print_r(int x, int y, t_cube *cube, int color)
{
	int	i;

	i = 0;
	while (i++ < 26)
	{
		ft_pixel(cube->img, x + i, y, color);
		ft_pixel(cube->img, x + i, y + 1, color);
		ft_pixel(cube->img, x + i, y + 21, color);
		ft_pixel(cube->img, x + i, y + 22, color);
	}
	print_r_part2(x, y, cube, color);
}

static void	print_r_part2(int x, int y, t_cube *cube, int color)
{
	int	j;
	int	i;
	int	z;

	j = 0;
	i = 26;
	z = 30;
	while (j++ < 40)
	{
		ft_pixel(cube->img, x, j + y, color);
		ft_pixel(cube->img, x + 1, j + y + 1, color);
		if (j < 21)
		{
			ft_pixel(cube->img, x + i + 1, j + y, color);
			ft_pixel(cube->img, x + i, j + y, color);
		}
		else
		{
			ft_pixel(cube->img, x + i / 2 + 1 - z, j + y, color);
			ft_pixel(cube->img, x + i / 2 - z, j + y, color);
			ft_pixel(cube->img, x + i / 2 + 2 - z, j + y, color);
		}
		z--;
	}
}

static void	print_e(int x, int y, t_cube *cube, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 26)
	{
		ft_pixel(cube->img, x + i, y, color);
		ft_pixel(cube->img, x + i, y + 1, color);
		ft_pixel(cube->img, x + i, y + 21, color);
		ft_pixel(cube->img, x + i, y + 22, color);
		ft_pixel(cube->img, x + i, y + 40, color);
		ft_pixel(cube->img, x + i, y + 41, color);
	}
	while (j++ < 40)
	{
		ft_pixel(cube->img, x, j + y, color);
		ft_pixel(cube->img, x + 1, j + y + 1, color);
	}
}
