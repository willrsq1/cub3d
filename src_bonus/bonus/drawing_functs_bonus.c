/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:36 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 17:01:28 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_do_draw_loop(t_img *img, t_draw plot, int color);
static void	draw(t_draw plot, int color, t_img *img);

void	draw_pov_player(t_cube *cube, t_player *player, int color, int coef)
{
	t_draw	plot;
	double	angle;
	int		pixel_column;

	fix_angle(&player->angle);
	pixel_column = 0;
	angle = player->angle + player->fov / 2;
	plot.x0 = player->x * coef;
	plot.y0 = player->y * coef;
	while (pixel_column <= WIN_WIDTH)
	{
		angle -= player->fov / WIN_WIDTH;
		plot.x1 = plot.x0 + coef * 2 * cosf(angle);
		plot.y1 = plot.y0 + coef * 2 * sinf(angle);
		draw(plot, color, cube->img);
		pixel_column++;
	}
}

static void	draw(t_draw plot, int color, t_img *img)
{
	plot.dx = abs(plot.x1 - plot.x0);
	plot.dy = -abs(plot.y1 - plot.y0);
	if (plot.x0 < plot.x1)
		plot.sx = 1;
	else
		plot.sx = -1;
	if (plot.y0 < plot.y1)
		plot.sy = 1;
	else
		plot.sy = -1;
	plot.err = plot.dx + plot.dy;
	ft_do_draw_loop(img, plot, color);
}

static void	ft_do_draw_loop(t_img *img, t_draw plot, int color)
{
	while (1)
	{
		ft_pixel(img, plot.y0, plot.x0, color);
		if (plot.x0 == plot.x1 && plot.y0 == plot.y1)
			break ;
		plot.e2 = 2 * plot.err;
		if (plot.e2 >= plot.dy)
		{
			plot.err = plot.dy + plot.err;
			plot.x0 += plot.sx;
		}
		if (plot.e2 <= plot.dx)
		{
			plot.err += plot.dx;
			plot.y0 += plot.sy;
		}
	}
}
