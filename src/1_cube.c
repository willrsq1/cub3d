/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_cube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:57:24 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/17 13:10:39 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	ft_init(char **argv, t_cube *cube, t_img *img);
static void	launch_mlx(t_cube *cube);
static void	launch_assets(t_cube *cube);
static void	launch_window(t_cube *cube);

void	ft_cube(char **argv)
{
	t_cube	cube;
	t_img	img;

	ft_init(argv, &cube, &img);
	launch_mlx(&cube);
	launch_assets(&cube);
	launch_window(&cube);
}

static void	ft_init(char **argv, t_cube *cube, t_img *img)
{
	ft_bzero(cube, sizeof(t_cube));
	ft_bzero(img, sizeof(t_img));
	cube->fd = -1;
	cube->ceiling_color = -1;
	cube->floor_color = -1;
	cube->map = ft_map(argv[1], cube);
	print_map(cube->map, cube->map_lenght, cube);
	ft_check_map_is_closed(cube, cube->map);
	get_player_position(cube);
	cube->img = img;
}

static void	launch_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
	{
		perror("at mlx_init in launch_mlx");
		ft_free_exit(cube);
	}
	cube->mlx_win = mlx_new_window(cube->mlx, WIN_WIDTH, WIN_HEIGHT, "Cube");
	if (!cube->mlx_win)
	{
		perror("at mlx_new_window in launch_mlx");
		ft_free_exit(cube);
	}
	cube->img->img_ptr = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->img->img_ptr)
	{
		perror("at mlx_new_image in launch_mlx");
		ft_free_exit(cube);
	}
	cube->img->addr = mlx_get_data_addr(cube->img->img_ptr, &cube->img->bpp, \
		&cube->img->size_line, &cube->img->endian);
	if (!cube->img->addr)
	{
		perror("at mlx_new_image in launch_mlx");
		ft_free_exit(cube);
	}
}

static void	launch_assets(t_cube *cube)
{
	get_img(cube, &cube->sprites[NORTH], cube->text_north);
	get_img(cube, &cube->sprites[SOUTH], cube->text_south);
	get_img(cube, &cube->sprites[WEST], cube->text_west);
	get_img(cube, &cube->sprites[EAST], cube->text_east);
}

static void	launch_window(t_cube *cube)
{
	ft_raycasting(cube, &cube->player);
	mlx_hook(cube->mlx_win, 2, 1L << 0, ft_key_hook, cube);
	mlx_hook(cube->mlx_win, 17, 1L << 17, ft_close, cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img_ptr, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img->img_ptr);
	cube->img->img_ptr = NULL;
	mlx_loop(cube->mlx);
}
