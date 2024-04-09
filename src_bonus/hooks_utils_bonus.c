/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:13:23 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 18:27:09 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

static void	ft_move_right(t_cube *cube);
static void	ft_move_left(t_cube *cube);

void	ft_key_pressed(int key, t_cube *cube)
{
	if (key == RIGHT_ARROW)
		cube->player.angle -= 0.07;
	if (key == LEFT_ARROW)
		cube->player.angle += 0.07;
	if (key == W_KEY)
	{
		cube->player.x += cosf(cube->player.angle) / 10;
		cube->player.y += sinf(cube->player.angle) / 10;
	}
	if (key == S_KEY)
	{
		cube->player.x -= cosf(cube->player.angle) / 10;
		cube->player.y -= sinf(cube->player.angle) / 10;
	}
	if (key == D_KEY)
		ft_move_right(cube);
	if (key == A_KEY)
		ft_move_left(cube);
}

static void	ft_move_right(t_cube *cube)
{
	if (cube->player.angle > 0 && cube->player.angle < PI)
	{
		cube->player.x -= cosf(cube->player.angle + PI / 2) / 10;
		cube->player.y -= sinf(cube->player.angle + PI / 2) / 10;
	}
	else
	{
		cube->player.x += cosf(cube->player.angle - PI / 2) / 10;
		cube->player.y += sinf(cube->player.angle - PI / 2) / 10;
	}
}

static void	ft_move_left(t_cube *cube)
{
	if (cube->player.angle > 0 && cube->player.angle < PI)
	{
		cube->player.x -= cosf(cube->player.angle - PI / 2) / 10;
		cube->player.y -= sinf(cube->player.angle - PI / 2) / 10;
	}
	else
	{
		cube->player.x += cosf(cube->player.angle + PI / 2) / 10;
		cube->player.y += sinf(cube->player.angle + PI / 2) / 10;
	}
}
