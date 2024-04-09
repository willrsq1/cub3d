/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:25:12 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/12 10:37:34 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static int	ft_atoi(char *s);
static int	ft_encode_rgb(int red, int green, int blue);

int	ft_get_color(int color, t_cube *cube, char *s)
{
	int		i;
	char	**tab;

	if (color != -1)
		ft_error("Multiple definitions for this element: ", s, s, cube);
	i = 2;
	while (s[i] && s[i] == ' ')
		i++;
	s[ft_strlen(s) - 1] = '\0';
	tab = ft_split(&s[i], ',');
	if (!tab || !tab[0] || !tab[1] || !tab[2] || tab[3])
	{
		ft_free_tab(tab);
		ft_error("Bad input for colors in line : ", s, s, cube);
	}
	color = ft_encode_rgb(ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	ft_free_tab(tab);
	if (color == -1)
		ft_error("Bad inputs for colors in line : ", s, s, cube);
	return (color);
}

static int	ft_atoi(char *s)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9' && i < 4)
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if (i == 0 || i == 4 || s[i] || result > 255)
		return (-1);
	return (result);
}

static int	ft_encode_rgb(int red, int green, int blue)
{
	if (red < 0 || green < 0 || blue < 0)
		return (-1);
	return (red << 16 | green << 8 | blue);
}

int	ft_atoi_cube(char c)
{
	if (c == ' ')
		return (1);
	if (c == '0' || c == '1')
		return (c - 48);
	if (c == 'N' || \
		c == 'S' || \
		c == 'E' || \
		c == 'W')
		return (c);
	if (c == 'D')
		return (CLOSED_DOOR);
	if (c == 'X')
		return (ENEMY);
	return (50);
}
