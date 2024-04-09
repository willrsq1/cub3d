/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_interface_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:30:10 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/21 22:12:16 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

static void	pause_screen_image(int key, t_cube *cube);
static void	difficulty(t_cube *cube);

void	ft_keys_interface(int key, t_cube *cube)
{
	if (cube->game_was_won)
		ft_free_exit(cube);
	if (!cube->welcome_window && key == ENTER_KEY && !cube->escape \
		&& !cube->help_menu && !cube->game_was_won)
		difficulty(cube);
	else if (cube->lost && key != SPACE_KEY)
		ft_free_exit(cube);
	else if (key == ESC_KEY || cube->escape)
	{
		ft_create_image(cube);
		esc_key_function(key, cube);
		ft_destroy_image(cube);
	}
	else if (key == H_KEY || cube->help_menu)
		help_menu_function(key, cube);
	else if (cube->difficulty_window && !cube->escape && cube->welcome_window)
		ft_difficulty(key, cube);
	else if (cube->win && key != SPACE_KEY)
		ft_levels(cube);
}

void	esc_key_function(int key, t_cube *cube)
{
	if (cube->escape)
	{
		if ((key == ENTER_KEY && cube->escape == PAUSE_RIGHT) || key == ESC_KEY)
			ft_free_exit(cube);
		else if (key == ENTER_KEY && cube->escape == PAUSE_LEFT)
		{
			cube->escape = 0;
			cube->start = ft_time();
			if (cube->help_menu)
				put_my_img_to_img(0, 0, cube->sprites[HELP], cube->img);
			else if (!cube->welcome_window)
				ft_landing_image(cube);
			else if (cube->difficulty_window)
				put_my_img_to_img(0, 0, \
					cube->sprites[cube->difficulty], cube->img);
		}
		else if (key == LEFT_ARROW || key == RIGHT_ARROW)
			pause_screen_image(key, cube);
		else
			put_my_img_to_img(0, 0, cube->sprites[cube->escape], cube->img);
		return ;
	}
	cube->escape = PAUSE_LEFT;
	put_my_img_to_img(0, 0, cube->sprites[PAUSE_LEFT], cube->img);
}

static void	pause_screen_image(int key, t_cube *cube)
{
	if (key == LEFT_ARROW)
	{
		cube->escape = PAUSE_LEFT;
		put_my_img_to_img(0, 0, cube->sprites[PAUSE_LEFT], cube->img);
	}
	else if (key == RIGHT_ARROW)
	{
		cube->escape = PAUSE_RIGHT;
		put_my_img_to_img(0, 0, cube->sprites[PAUSE_RIGHT], cube->img);
	}
}

void	help_menu_function(int key, t_cube *cube)
{
	ft_create_image(cube);
	if (cube->help_menu)
	{
		cube->help_menu = 0;
		if (key == ENTER_KEY && !cube->welcome_window)
			put_my_img_to_img(0, 0, cube->sprites[LANDING], cube->img);
		else if (cube->escape)
			put_my_img_to_img(0, 0, cube->sprites[cube->escape], cube->img);
		else if (!cube->welcome_window && cube->level == 0)
			put_my_img_to_img(0, 0, cube->sprites[LANDING], cube->img);
		else if (!cube->welcome_window)
			put_my_img_to_img(0, 0, cube->sprites[cube->level], cube->img);
		else if (cube->difficulty_window)
			put_my_img_to_img(0, 0, cube->sprites[cube->difficulty], cube->img);
		else
			put_my_img_to_img(0, 0, cube->sprites[HELP], cube->img);
	}
	else
	{
		cube->help_menu = 1;
		put_my_img_to_img(0, 0, cube->sprites[HELP], cube->img);
	}
	ft_destroy_image(cube);
}

static void	difficulty(t_cube *cube)
{
	if (cube->level == 0 && !cube->difficulty_window)
	{
		cube->difficulty = EASY;
		cube->difficulty_window = 1;
		cube->level = LEVEL_1;
		ft_create_image(cube);
		put_my_img_to_img(0, 0, cube->sprites[EASY], cube->img);
		ft_destroy_image(cube);
	}
	else
	{
		cube->start = ft_time();
		cube->difficulty_window = 0;
	}
	cube->welcome_window = 1;
}
