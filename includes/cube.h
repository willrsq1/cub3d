/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:57:50 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/17 13:10:23 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "cube_defines.h"

typedef struct s_cube	t_cube;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			img_width;
	int			img_height;
}	t_img;

typedef struct s_player
{
	double		x;
	double		y;
	double		prev_x;
	double		prev_y;
	double		vector_x;
	double		vector_y;
	double		direction;
	t_img		*texture;
	t_cube		*cube;
	double		fov;
	double		x_wall;
}	t_player;

typedef struct s_cube
{
	int			**map;
	int			fd;
	int			map_lenght;
	int			map_width;
	t_player	player;
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	char		*text_north;
	char		*text_south;
	char		*text_west;
	char		*text_east;
	int			ceiling_color;
	int			floor_color;
	t_img		sprites[5];
	int			id;
}	t_cube;

/*	1_cube.c			*/

void	ft_cube(char **argv);

/*	2_raycasting.c		*/

void	ft_raycasting(t_cube *cube, t_player *player);

/*	3_hooks.c			*/

int		ft_key_hook(int key, t_cube *cube);
void	ft_update_image(t_cube *cube);
void	ft_destroy_image(t_cube *cube);
int		ft_close(t_cube *cube);

/*	4_images.c			*/

int		get_pixel_img(t_img img, int x, int y);
void	put_my_img_to_img(int x_start, int y_start, t_img tex, t_img *img);
void	get_img(t_cube *cube, t_img *img, char *path);

/*	cube_utils.c		*/

int		ft_valid_pos(t_cube *cube, double x, double y);
void	ft_free_exit(t_cube *cube);
void	ft_error(char *s1, char *s2, char *s3, t_cube *cube);
int		ft_atoi_cube(char c);

/*	hooks_utils.c		*/

void	ft_key_pressed(int key, t_cube *cube);
bool	ft_check_player_position(t_cube *cube);

/*	raycasting_utils.c	*/

void	fix_angle(double *angle);
double	ft_distance(double x, double y, double x0, double y0);
void	ft_wall_pixel(t_cube *cube, int x, int y, double colum_size);
void	ft_pixel(t_img *img, int x, int y, int color);

/*	INIT	*/

/*	colors.c			*/

int		ft_get_color(int color, t_cube *cube, char *s);

/*	ft_split.c			*/

void	ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);

/*	map_error.c			*/

void	ft_check_map_is_closed(t_cube *cube, int **map);
bool	ft_format(char *s);
void	skip_elements(int fd, t_cube *cube);

/*	map.c				*/

int		**ft_map(char *path, t_cube *cube);

/*	player_init.c		*/

void	get_player_position(t_cube *cube);
void	print_map(int **map, int map_lenght, t_cube *cube);

/*	textures.c			*/

void	ft_textures_and_colors(t_cube *cube, int fd, char *s, int count);
void	ft_empty_line_in_map(t_cube *cube, char *buff, int fd, int x);

#endif