/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:24:23 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:24:24 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_set(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		fnbw(char *str, char *set)
{
	int ret;
	int i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	ret = 1;
	while (str[i])
	{
		if (is_set(str[i], set))
		{
			while (is_set(str[i], set))
				i++;
			if (i < ft_strlen(str))
				ret++;
		}
		i++;
	}
	return (ret);
}

char	**split(char *str, char *set)
{
	long int	nbw;
	char		**tab;
	long int	i;

	while (is_set(*str, set))
		str++;
	i = 0;
	nbw = fnbw(str, set);
	if (!(tab = malloc(sizeof(char*) * (nbw + 1))))
		return (0);
	tab[nbw] = 0;
	if (nbw == 0)
		return (tab);
	while (i + 1 < nbw)
	{
		if (!(tab[i++] = ft_substr(str, 0, ft_strchr(str, set) - str)))
			return (NULL);
		str = ft_strchr(str, set);
		while (is_set(*str, set))
			str++;
	}
	if (nbw != 0)
		tab[nbw - 1] = ft_strdup(str);
	return (tab);
}
