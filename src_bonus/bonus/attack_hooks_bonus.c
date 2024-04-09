/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_hooks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:19:57 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:28 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_key_enemy_dead(int key, t_cube *cube, int range);
static void	ft_key_enemy_hurt(int key, t_cube *cube, int range);
static void	ft_key_enemy_alive(int key, t_cube *cube, int range);
static void	ft_key_enemy_alive_2(t_cube *cube, double i);

void	ft_key_enemy(int key, t_cube *cube)
{
	int	range;

	range = ATTACK_RANGE_SWORD;
	if (cube->weapon == GUN)
		range = ATTACK_RANGE_GUN;
	if (key == ONE_KEY)
		cube->weapon = SWORD;
	if (key == TWO_KEY)
		cube->weapon = GUN;
	if (key != SPACE_KEY)
		return ;
	ft_key_enemy_dead(key, cube, range);
	ft_key_enemy_hurt(key, cube, range);
	ft_key_enemy_alive(key, cube, range);
}

static void	ft_key_enemy_dead(int key, t_cube *cube, int range)
{
	double	i;
	int		return_value;

	i = 0.01;
	while (i < range)
	{
		return_value = ft_valid_pos_enemy(cube, cube->player.x + \
			cosf(cube->player.angle) * i, cube->player.y + \
			sinf(cube->player.angle) * i);
		if (return_value == DEAD_ENEMY)
			break ;
		if (return_value == END)
			i = range;
		i += 0.01;
	}
	if (i < range && key == SPACE_KEY)
	{
		if (cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
			* i)][(int)(cube->player.y + sinf(cube->player.angle) \
			* i)] != 1)
			cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
				* i)][(int)(cube->player.y + sinf(cube->player.angle) \
				* i)] = 0;
		cube->attacking = 1;
	}
}

static void	ft_key_enemy_hurt(int key, t_cube *cube, int range)
{
	double	i;
	int		return_value;

	i = 0.01;
	while (i < range)
	{
		return_value = ft_valid_pos_enemy(cube, cube->player.x + \
			cosf(cube->player.angle) * i, cube->player.y + \
			sinf(cube->player.angle) * i);
		if (return_value == HURT_ENEMY)
			break ;
		if (return_value == END)
			i = range;
		i += 0.01;
	}
	if (i < range && key == SPACE_KEY)
	{
		if (cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
			* i)][(int)(cube->player.y + sinf(cube->player.angle) \
			* i)] != 1 && ++cube->kill_count)
			cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
				* i)][(int)(cube->player.y + sinf(cube->player.angle) \
				* i)] = DEAD_ENEMY;
		cube->attacking = 1;
	}
}

static void	ft_key_enemy_alive(int key, t_cube *cube, int range)
{
	double	i;
	int		return_value;

	i = 0.01;
	return_value = 0;
	while (i < range && return_value != ENEMY)
	{
		return_value = ft_valid_pos_enemy(cube, cube->player.x + \
			cosf(cube->player.angle) * i, cube->player.y + \
			sinf(cube->player.angle) * i);
		if (return_value == END)
			i = range;
		i += 0.01;
	}
	if (i < range && key == SPACE_KEY)
		ft_key_enemy_alive_2(cube, i);
}

static void	ft_key_enemy_alive_2(t_cube *cube, double i)
{
	if (cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
		* i)][(int)(cube->player.y + sinf(cube->player.angle) \
		* i)] != 1)
	{
		cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
			* i)][(int)(cube->player.y + sinf(cube->player.angle) \
			* i)] = HURT_ENEMY;
		if (cube->weapon == SWORD)
			cube->map[(int)(cube->player.x + cosf(cube->player.angle) \
				* i)][(int)(cube->player.y + sinf(cube->player.angle) \
				* i)] = DEAD_ENEMY;
		cube->attacking = 1;
	}
}
