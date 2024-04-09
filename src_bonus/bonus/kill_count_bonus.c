/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_count_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:56:50 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/15 11:37:36 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static char	*ft_itoa(int nb);
static int	len_nb(unsigned int nb);

void	ft_kill_count(t_cube *cube)
{
	char	*nb;

	nb = ft_itoa(cube->kill_count);
	if (!nb)
		return ;
	mlx_string_put(cube->mlx, cube->mlx_win, WIN_WIDTH * 0.9, \
		WIN_HEIGHT * 0.99, RED, "KILL COUNT : ");
	mlx_string_put(cube->mlx, cube->mlx_win, WIN_WIDTH * 0.97, \
		WIN_HEIGHT * 0.99, RED, nb);
	free(nb);
}

static char	*ft_itoa(int nb)
{
	char	*str;
	int		i;

	i = len_nb(nb);
	str = ft_calloc(i + 2, 1);
	if (!str)
		return (NULL);
	i--;
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}

static int	len_nb(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 0 && ++i)
		nb = nb / 10;
	return (i);
}
