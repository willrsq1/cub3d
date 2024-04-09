/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:57:37 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/15 11:35:52 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

int	main(int argc, char **argv)
{
	char	*s[2];

	if (argc > 2)
		return (write(2, "Too many args\n", 14), 1);
	s[1] = "maps/level_1.cub";
	if (argc == 2)
		ft_cube(argv, 0, 0);
	else
		ft_cube(s, 0, 0);
	return (0);
}
