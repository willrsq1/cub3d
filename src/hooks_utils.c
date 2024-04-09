/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:13:23 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 18:27:48 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_move_right(t_cube *cube);
static void	ft_move_left(t_cube *cube);

void	ft_key_pressed(int key, t_cube *cube)
{
	if (key == ESC_KEY)
		ft_free_exit(cube);
	if (key == RIGHT_ARROW)
		cube->player.direction -= 0.05;
	if (key == LEFT_ARROW)
		cube->player.direction += 0.05;
	if (key == W_KEY)
	{
		cube->player.x += cosf(cube->player.direction) / 10;
		cube->player.y += sinf(cube->player.direction) / 10;
	}
	if (key == S_KEY)
	{
		cube->player.x -= cosf(cube->player.direction) / 10;
		cube->player.y -= sinf(cube->player.direction) / 10;
	}
	if (key == D_KEY)
		ft_move_right(cube);
	if (key == A_KEY)
		ft_move_left(cube);
}

bool	ft_check_player_position(t_cube *cube)
{
	if (ft_valid_pos(cube, cube->player.x, cube->player.y) > 0)
	{
		if (ft_valid_pos(cube, cube->player.prev_x, cube->player.y) <= 0)
			cube->player.x = cube->player.prev_x;
		else if (ft_valid_pos(cube, cube->player.x, cube->player.prev_y) <= 0)
			cube->player.y = cube->player.prev_y;
		else
		{
			cube->player.x = cube->player.prev_x;
			cube->player.y = cube->player.prev_y;
			return (CANCEL_THE_MOVEMENT);
		}
	}
	return (POSITION_IS_GOOD);
}

static void	ft_move_right(t_cube *cube)
{
	if (cube->player.direction > 0 && cube->player.direction < PI)
	{
		cube->player.x -= cosf(cube->player.direction + PI / 2) / 10;
		cube->player.y -= sinf(cube->player.direction + PI / 2) / 10;
	}
	else
	{
		cube->player.x += cosf(cube->player.direction - PI / 2) / 10;
		cube->player.y += sinf(cube->player.direction - PI / 2) / 10;
	}
}

static void	ft_move_left(t_cube *cube)
{
	if (cube->player.direction > 0 && cube->player.direction < PI)
	{
		cube->player.x -= cosf(cube->player.direction - PI / 2) / 10;
		cube->player.y -= sinf(cube->player.direction - PI / 2) / 10;
	}
	else
	{
		cube->player.x += cosf(cube->player.direction + PI / 2) / 10;
		cube->player.y += sinf(cube->player.direction + PI / 2) / 10;
	}
}
