/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:56:33 by jdyer             #+#    #+#             */
/*   Updated: 2019/11/11 19:38:17 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_in_set(char c, char *set)
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

char	*ft_strchr(const char *s, char *set)
{
	int		cpt;

	cpt = 0;
	while (!is_in_set(s[cpt], set) && s[cpt] != '\0')
		cpt++;
	if (s[cpt] == '\0')
		return (NULL);
	return ((char *)&s[cpt]);
}
