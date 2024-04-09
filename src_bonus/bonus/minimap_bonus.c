/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:41:43 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 20:45:06 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_draw_enemies(t_cube *cube, double coef, int x, int y);
static void	ft_draw_square(int size, int y, int x, t_cube *cube);

void	ft_minimap(t_cube *cube)
{
	int		y;
	int		x;
	int		coef;

	y = 0;
	coef = WIN_WIDTH / 100;
	if (coef * cube->map_width > WIN_WIDTH)
		coef = WIN_HEIGHT / cube->map_width * 2;
	while (y < cube->map_lenght)
	{
		x = 0;
		while (cube->map[y][x] != END)
		{
			ft_draw_square(coef, y, x, cube);
			if (cube->map[y][x] == ENEMY && cube->minimap && cube->animation)
				put_my_img_to_img((x - 1) * coef, (y - 1) * \
				coef, cube->sprites[CAT1], cube->img);
			x++;
		}
		y++;
	}
	draw_pov_player(cube, &cube->player, RED, coef);
	put_my_img_to_img((cube->player.y - 1) * coef, \
		(cube->player.x - 1.5) * coef, cube->sprites[MINNIE], cube->img);
	ft_draw_enemies(cube, coef, 0, 0);
}

static void	ft_draw_enemies(t_cube *cube, double coef, int x, int y)
{
	y = 0;
	if (!cube->animation)
		return ;
	while (y < cube->map_lenght)
	{
		x = 0;
		while (cube->map[y][x] != END)
		{
			if (cube->map[y][x] == ENEMY)
				put_my_img_to_img((x - 1) * coef, (y - 1) * coef, \
				cube->sprites[CAT1], cube->img);
			if (cube->map[y][x] == HURT_ENEMY)
				put_my_img_to_img((x - 1) * coef, (y - 1) * coef, \
				cube->sprites[MINI_HURT], cube->img);
			if (cube->map[y][x] == DEAD_ENEMY)
				put_my_img_to_img((x - 0.5) * coef, (y - 0.5) * coef, \
				cube->sprites[TOMB], cube->img);
			x++;
		}
		y++;
	}
}

static void	ft_draw_square(int size, int y, int x, t_cube *cube)
{
	int	i;
	int	j;

	j = -1;
	while (++j <= size)
	{
		i = 0;
		while (i <= size)
		{
			if (i == 0 || j == 0 || i == size || j == size)
				ft_pixel(cube->img, x * size + i, y * size + j, DARK_GRAY);
			else
			{
				if (cube->map[y][x] == CLOSED_DOOR)
					ft_pixel(cube->img, x * size + i, y * size + j, CD_COLOR);
				else if (cube->map[y][x] == OPENED_DOOR)
					ft_pixel(cube->img, x * size + i, y * size + j, OP_COLOR);
				else if (cube->map[y][x] == WALL)
					ft_pixel(cube->img, x * size + i, y * size + j, BLACK);
				else
					ft_pixel(cube->img, x * size + i, y * size + j, GRAY);
			}
			i++;
		}
	}
}

void	ft_jump(t_cube *cube)
{
	size_t	i;
	int		height;

	height = cube->height;
	i = 135;
	while (i > 110)
	{
		if (i > 120)
			cube->height += i / 15 + 15;
		else
			cube->height += i % 110;
		ft_update_image(cube);
		i--;
	}
	while (cube->height > height)
	{
		cube->height -= 15;
		ft_update_image(cube);
	}
	cube->height = height;
}
