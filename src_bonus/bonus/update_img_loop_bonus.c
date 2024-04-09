/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_img_loop_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:40:06 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/21 22:10:39 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_put_welcome_frame(t_cube *cube);

int	update_loop(t_cube *cube)
{
	if (!cube->welcome_window && !cube->escape && !cube->help_menu && \
		cube->level == 0)
	{
		ft_create_image(cube);
		ft_put_welcome_frame(cube);
		ft_destroy_image(cube);
		return (1);
	}
	if (cube->difficulty_window || !cube->welcome_window)
		return (1);
	if (!cube->escape && !cube->lost && !cube->help_menu && !cube->win)
	{
		ft_update_image(cube);
		if (cube->map_has_enemies)
			ft_pollution(cube, cube->map);
	}
	return (1);
}

void	ft_update_image(t_cube *cube)
{
	ft_create_image(cube);
	ft_raycasting(cube, &cube->player);
	minimap_weapons_door_message(cube);
	if (cube->level == LEVEL_2)
		put_my_img_to_img(WIN_WIDTH * 0.4, 0, cube->sprites[SUN], cube->img);
	ft_destroy_image(cube);
	ft_kill_count(cube);
}

static void	ft_put_welcome_frame(t_cube *cube)
{
	time_t	time;

	time = ft_time() % 1119;
	if (time < 140)
		put_my_img_to_img(0, 0, cube->sprites[LANDING1], cube->img);
	else if (time < 280)
		put_my_img_to_img(0, 0, cube->sprites[LANDING3], cube->img);
	else if (time < 420)
		put_my_img_to_img(0, 0, cube->sprites[LANDING2], cube->img);
	else if (time < 560)
		put_my_img_to_img(0, 0, cube->sprites[LANDING3], cube->img);
	else if (time < 700)
		put_my_img_to_img(0, 0, cube->sprites[LANDING1], cube->img);
	else if (time < 840)
		put_my_img_to_img(0, 0, cube->sprites[LANDING4], cube->img);
	else if (time < 980)
		put_my_img_to_img(0, 0, cube->sprites[LANDING5], cube->img);
	else if (time < 1120)
		put_my_img_to_img(0, 0, cube->sprites[LANDING6], cube->img);
}
