/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:57:45 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 10:54:47 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

void	fix_angle(double *angle)
{
	if (*angle >= PII)
		*angle -= PII;
	if (*angle <= 0)
		*angle += PII;
}

double	ft_distance(double x, double y, double x0, double y0)
{
	double	dist;

	x = x0 - x;
	if (x < 0)
		x *= -1;
	y = y0 - y;
	if (y < 0)
		y *= -1;
	dist = sqrt(x * x + y * y);
	return (dist);
}

void	ft_wall_pixel(t_cube *cube, int x, int y, double colum_size)
{
	double			x_wall;
	double			y_wall;
	unsigned int	color;

	x_wall = cube->player.x_wall * cube->sprites[cube->id].img_height;
	y_wall = ((double)colum_size / (double)cube->sprites[cube->id].img_width);
	y_wall = (y - (WIN_HEIGHT / 2 - (colum_size / 2) + cube->height)) / y_wall;
	color = get_pixel_img(cube->sprites[cube->id], x_wall, y_wall);
	if (color == 0xFFFFFF && cube->id >= CAT1 && cube->id <= CAT4)
		color = PASTEL_PINK;
	ft_pixel(cube->img, x, y, color);
}

void	ft_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && y < WIN_HEIGHT && x < WIN_WIDTH)
	{
		dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
