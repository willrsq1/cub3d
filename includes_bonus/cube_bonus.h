/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:57:50 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/15 08:57:20 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_BONUS_H
# define CUBE_BONUS_H

# include "cube_defines_bonus.h"

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
	double		vector_x_start;
	double		vector_y_start;
	double		vector_x;
	double		vector_y;
	double		angle;
	int			color;
	t_img		*texture;
	t_cube		*cube;
	double		fov;
	double		x_wall;
}	t_player;

typedef struct s_cube
{
	int			**map;
	int			id;
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
	int			minimap;
	bool		door_message;
	int			animation;
	int			mouse_x;
	int			mouse_y;
	bool		mouse_drag;
	int			height;
	t_img		sprites[SPRITES_MAX_NB];
	time_t		start;
	bool		enemy;
	bool		attacking;
	bool		welcome_window;
	bool		difficulty_window;
	bool		help_menu;
	bool		lost;
	bool		win;
	bool		map_has_enemies;
	bool		game_was_won;
	int			escape;
	int			weapon;
	double		angle;
	int			level;
	int			difficulty;
	int			kill_count;
}	t_cube;

/*	1_cube.c			*/

void	ft_cube(char **argv, int level, int difficulty);

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

int		ft_valid_pos_bonus(t_cube *cube, double x, double y);
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

int		**ft_map(char *path, t_cube *cube);
time_t	ft_time(void);

void	ft_free_exit(t_cube *cube);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi_cube(char c);

void	get_player_position(t_cube *cube);

void	ft_update_image(t_cube *cube);
void	ft_pixel(t_img *img, int x, int y, int color);
void	put_my_img_to_img(int x_start, int y_start, t_img tex, t_img *img);
void	get_img(t_cube *cube, t_img *img, char *path);
int		update_loop(t_cube *cube);

int		ft_close(t_cube *cube);
int		ft_key_hook(int key, t_cube *cube);
int		get_pixel_img(t_img img, int x, int y);

void	ft_raycasting(t_cube *cube, t_player *player);

double	ft_distance(double x, double y, double x0, double y0);

void	ft_error(char *s1, char *s2, char *s3, t_cube *cube);
int		ft_close(t_cube *cube);

void	print_map(int **map, int map_lenght, t_cube *cube);

void	ft_textures_and_colors(t_cube *cube, int fd, char *s, int count);
void	skip_elements(int fd, t_cube *cube);

void	ft_doors(int key, t_cube *cube);
void	ft_destroy_image(t_cube *cube);

void	ft_check_map_is_closed(t_cube *cube, int **map);
bool	ft_format(char *s);

void	print_door_message(t_cube *cube);
void	fix_angle(double *angle);

void	ft_minimap(t_cube *cube);
char	**ft_split(char const *s, char c);
int		ft_get_color(int color, t_cube *cube, char *s);
void	ft_free_tab(char **tab);

void	print_door_message(t_cube *cube);
void	print_s(int x, int y, t_cube *cube, int color);
void	print_x(int x, int y, t_cube *cube, int color);

void	draw_pov_player(t_cube *cube, t_player *player, int color, int coef);
int		handle_mouse_move(int x, int y, t_cube *cube);
int		handle_mouse_click(int key, int x, int y, t_cube *cube);

void	ft_hooks_bonus(t_cube *cube);
void	ft_key_hook_bonus(int key, t_cube *cube);
void	minimap_weapons_door_message(t_cube *cube);
void	ft_key_pressed(int key, t_cube *cube);
bool	ft_check_player_position(t_cube *cube);
void	put_msg(t_cube *cube);
void	ft_wall_pixel(t_cube *cube, int x, int y, double colum_size);
void	ft_now(t_cube *cube);
void	draw_enemy(t_cube *cube, t_player *player, double angle, int x);
void	draw_enemy_back(t_cube *cube, t_player *player, double angle, int x);
int		ft_valid_pos_enemy(t_cube *cube, double x, double y);
void	draw_column_enemy(double dist, t_cube *cube, int x);
int		ft_cat_frame(t_cube *cube);
void	ft_key_enemy(int key, t_cube *cube);
void	ft_jump(t_cube *cube);
void	ft_create_image(t_cube *cube);
void	ft_pollution(t_cube *cube, int **map);
void	esc_key_function(int key, t_cube *cube);
void	help_menu_function(int key, t_cube *cube);

void	ft_free(t_cube *cube);
void	ft_levels(t_cube *cube);
void	ft_keys_interface(int key, t_cube *cube);
void	launch_assets(t_cube *cube);
void	ft_landing_image(t_cube *cube);
void	ft_difficulty(int key, t_cube *cube);

void	ft_kill_count(t_cube *cube);
#endif