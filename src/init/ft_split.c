/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:43 by marvin            #+#    #+#             */
/*   Updated: 2023/08/08 16:07:28 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	ft_lenword(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && sep != str[i])
		i++;
	return (i);
}

static int	ft_nbsep(char *str, char c)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			nb_word++;
		while (str[i] && c != str[i])
			i++;
	}
	return (nb_word);
}

static char	*ft_tab(char *tab, char set)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_lenword(tab, set);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = tab[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;
	int		i;
	int		j;
	int		nb_lines;

	if (s == NULL)
		return (NULL);
	nb_lines = ft_nbsep((char *)s, c);
	newstr = (char **)malloc(sizeof(char *) * (nb_lines + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < nb_lines)
	{
		while (s[i] != '\0' && c == s[i])
			i++;
		newstr[j] = ft_tab((char *)&s[i], c);
		if (!newstr[j])
			return (ft_free_tab(newstr), NULL);
		j++;
		while (s[i] && c != s[i])
			i++;
	}
	return (newstr[nb_lines] = NULL, newstr);
}
