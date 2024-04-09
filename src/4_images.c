/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_images.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:26:24 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/11 01:23:04 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	get_pixel_img(t_img img, int x, int y)
{
	unsigned int	pix;

	if (x < 0 || y < 0)
		return (0);
	pix = *(unsigned int *)((img.addr + \
		(y * img.size_line) + (x * img.bpp / 8)));
	return ((int)pix);
}

void	put_my_img_to_img(int x_start, int y_start, t_img tex, t_img *img)
{
	int				i;
	int				y;
	unsigned int	pix;

	i = 0;
	while (i < tex.img_height)
	{
		y = 0;
		while (y < tex.img_width)
		{
			pix = get_pixel_img(tex, y, i);
			if (pix != 0xFF000000)
				ft_pixel(img, x_start + y, y_start + i, pix);
			y++;
		}
		i++;
	}
}

void	get_img(t_cube *cube, t_img *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(cube->mlx, path, \
		&img->img_width, &img->img_height);
	if (img->img_ptr == NULL)
	{
		write(2, "error: at mlx_xpm_file_to_image in get_img ", 43);
		perror(path);
		ft_free_exit(cube);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, \
		&img->size_line, &img->endian);
	if (img->addr == NULL)
	{
		write(2, "error: at mlx_get_data_addr in get_img: ", 40);
		perror(path);
		ft_free_exit(cube);
	}
}
