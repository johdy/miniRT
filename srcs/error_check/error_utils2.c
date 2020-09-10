/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:02:33 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:02:35 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_not_float(char *word)
{
	int i;
	int virg;

	virg = 0;
	i = 0;
	if (word[i] == '-')
		i++;
	while (word[i])
	{
		if (word[i] == '.' && virg == 0)
		{
			i++;
			virg = 1;
		}
		else if (word[i] == '.' && virg == 1)
			return (1);
		else if (ft_isdigit(word[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int		is_not_int(char *word)
{
	int i;

	i = 0;
	if (word[i] == '-')
		i++;
	while (word[i])
	{
		if (ft_isdigit(word[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int		check_neg_pb(char *word)
{
	int i;
	int virg;

	i = 0;
	virg = 0;
	if (word[i] == '-')
		i++;
	while (word[i])
	{
		if (word[i] == '-' && virg == 0)
			return (1);
		if (word[i] == ',')
			virg = 1;
		else
			virg = 0;
		i++;
	}
	return (0);
}

int		check_float_pb(char *word)
{
	int i;
	int check;

	check = 0;
	i = 0;
	while (word[i])
	{
		if (word[i] == '.' && check == 0)
			check = 1;
		else if (word[i] == '.' && check == 1)
			return (1);
		if (word[i] == ',')
			check = 0;
		i++;
	}
	return (check_neg_pb(word));
}
