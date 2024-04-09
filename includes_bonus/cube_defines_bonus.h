/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_defines_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:20:38 by wruet-su          #+#    #+#             */
/*   Updated: 2023/10/27 18:24:45 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_DEFINES_BONUS_H
# define CUBE_DEFINES_BONUS_H

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include <sys/time.h>
# include <unistd.h>
# define CLOSED_DOOR 2
# define WALL 1
# define END -1
# define OPENED_DOOR -2
# define OPENING_DOOR1 -3
# define OPENING_DOOR2 -4
# define ENEMY -10
# define HURT_ENEMY -11
# define DEAD_ENEMY -12
# define NEW_ENEMY -13

# define SPAWN_TIME 5000
# define ATTACK_RANGE_SWORD 2
# define ATTACK_RANGE_GUN 6

# define MINNIE 0
# define CAT1 1
# define CAT2 2
# define CAT3 3
# define CAT4 4
# define DOOR 5
# define BRICK 6
# define NORTH 7
# define SOUTH 8
# define WEST 9
# define EAST 10
# define CAT0 11
# define CAT_HURT 12
# define CAT_DEAD 13
# define SWORD 14
# define SWORD2 15
# define GUN 16
# define GUN2 17
# define LANDING 18
# define PAUSE_LEFT 19
# define PAUSE_RIGHT 20
# define LOST 21
# define HELP 22
# define WIN 23
# define TOMB 24
# define MINI_HURT 25
# define EASY 26
# define HARD 27
# define IMPOSSIBLE 28
# define LEVEL_1 29
# define LEVEL_2 30
# define LEVEL_3 31
# define LEVEL_4 32
# define LEVEL_5 33
# define LEVEL_6 34
# define LEVEL_7 35
# define LEVEL_8 36
# define FINAL_WIN 37
# define SUN 38
# define LANDING1 39
# define LANDING2 40
# define LANDING3 41
# define LANDING4 42
# define LANDING5 43
# define LANDING6 44
# define SPRITES_MAX_NB 50

# define CD_COLOR 0x98FF98
# define OP_COLOR 0xADD8E6

# define X 1
# define CANCEL_THE_MOVEMENT 1
# define POSITION_IS_GOOD 0
# define ESC_KEY 65307
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363
# define ENTER_KEY 65293
# define ONE_KEY 49
# define TWO_KEY 50
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define Z_KEY 122
# define M_KEY 109
# define H_KEY 104
# define P_KEY 112
# define U_KEY 117
# define J_KEY 106
# define N_KEY 98
# define B_KEY 110
# define R_KEY 114
# define PLUS_KEY 61
# define MINUS_KEY 45
# define SPACE_KEY 32

# define PI2 1.570796000000000081087137004942633211612701416015625
# define PI  3.141592999999999857863031138549558818340301513671875
# define PII 6.283184999999999575948095298372209072113037109375
# define PI3 4.7123889923095703125
# define FOV 1.17072000
# define RESOLUTION 0.0001
# define WIN_WIDTH 1300
# define WIN_HEIGHT 800
# define CEILING_COLOR 0x00FFFF
# define FLOOR_COLOR 0xFFD700

# define RED 0xFF5050
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define MAROON 0x800000
# define CYAN 0x00FFFF
# define BEACH_YELLOW 0xFFD700
# define PASTEL_PINK 0xFFB6C1
# define PASTEL_YELLOW 0xFFFF99
# define PASTEL_BLUE 0xADD8E6
# define PASTEL_GREEN 0x98FB98
# define PASTEL_PURPLE 0xE6E6FA
# define PASTEL_ORANGE 0xFFDAB9
# define PASTEL_MINT 0x98FF98
# define PASTEL_PEACH 0xFFDAB9
# define PASTEL_LAVENDER 0xE6E6FA
# define PASTEL_BEIGE 0xF5F5DC
# define GRAY 0xE0E0E0
# define DARK_GRAY 0xA0A0A0
# define PASTEL_LILAC   0xC8A2C8
# define PASTEL_SKY     0xB0E2FF
# define PASTEL_SALMON  0xFA8072
# define PASTEL_MAUVE   0xE0B0FF
# define PASTEL_SEAFOAM 0x7FFFD4
# define PASTEL_CORAL   0xFF6F61
# define PASTEL_APRICOT 0xFDD5B1
# define PASTEL_TURQUOISE 0xAFEEEE
# define DARK_RED       0x8B0000
# define NAVY_BLUE        0x000080
# define BURGUNDY       0x800000
# define MAROON         0x800000
# define CRIMSON        0xDC143C
# define BRICK_RED      0xB22222
# define FIREBRICK      0xB22222
# define WINE_RED       0x722F37
# define OXBLOOD_RED    0x800020
# define RUBY_RED       0x9B111E
# define GARNET         0x6A2323
# define SANGUINE       0x872019
# define MAHOGANY       0xC04000
# define CHERRY_RED     0xE34234
# define BARN_RED       0x7C0A02
# define CRANBERRY      0x9B1B30
# define CARMINE        0x960018
# define CHILI_RED      0xE23D28
# define ROSEWOOD       0x65000B
# define TOMATO_RED     0xFF6347
# define VERMILION      0xE34234

typedef struct s_draw
{
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}			t_draw;

#endif