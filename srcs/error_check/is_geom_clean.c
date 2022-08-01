/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_geom_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:02:49 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:02:50 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_sp(char **words)
{
	double ray;

	if (!words[1] || !words[2] || !words[3])
		return (err_clean_table(words, 31));
	if (words[4])
		return (err_clean_table(words, 30));
	if (check_tuple(words[1]) == 2 || check_tuple(words[3]) == 2)
		return (err_clean_table(words, 32));
	if (check_color(words[3]) != 1)
		return (err_clean_table(words, 34));
	ray = atof(words[2]);
	if (ray < 0 || is_not_float(words[2]))
		return (err_clean_table(words, 33));
	return (1);
}

int	check_pl(char **words)
{
	if (!words[1] || !words[2] || !words[3])
		return (err_clean_table(words, 41));
	if (words[4])
		return (err_clean_table(words, 40));
	if (check_tuple(words[1]) == 2 || check_tuple(words[2]) == 2)
		return (err_clean_table(words, 42));
	if (check_tuple(words[3]) == 2)
		return (err_clean_table(words, 42));
	if (check_color(words[3]) != 1)
		return (err_clean_table(words, 44));
	if (check_orient(words[2]) != 1)
		return (err_clean_table(words, 45));
	return (1);
}

int	check_tr(char **words)
{
	if (!words[1] || !words[2] || !words[3] || !words[4])
		return (err_clean_table(words, 51));
	if (words[5])
		return (err_clean_table(words, 50));
	if (check_tuple(words[1]) == 2 || check_tuple(words[2]) == 2)
		return (err_clean_table(words, 52));
	if (check_tuple(words[3]) == 2 || check_tuple(words[4]) == 2)
		return (err_clean_table(words, 52));
	if (check_color(words[4]) != 1)
		return (err_clean_table(words, 54));
	return (1);
}

int	check_sq(char **words)
{
	double height;

	if (!words[1] || !words[2] || !words[3] || !words[4])
		return (err_clean_table(words, 61));
	if (words[5])
		return (err_clean_table(words, 60));
	if (check_tuple(words[1]) == 2 || check_tuple(words[2]) == 2)
		return (err_clean_table(words, 62));
	if (check_tuple(words[4]) == 2)
		return (err_clean_table(words, 62));
	if (check_color(words[4]) != 1)
		return (err_clean_table(words, 64));
	if (check_orient(words[2]) != 1)
		return (err_clean_table(words, 65));
	height = atof(words[3]);
	if (height < 0 || is_not_float(words[3]))
		return (err_clean_table(words, 63));
	return (1);
}

int	check_cy(char **words)
{
	double height;
	double width;

	if (!words[1] || !words[2] || !words[3] || !words[4] || !words[5])
		return (err_clean_table(words, 71));
	if (words[6])
		return (err_clean_table(words, 70));
	if (check_tuple(words[1]) == 2 || check_tuple(words[2]) == 2)
		return (err_clean_table(words, 72));
	if (check_tuple(words[5]) == 2)
		return (err_clean_table(words, 72));
	if (check_color(words[5]) != 1)
		return (err_clean_table(words, 74));
	if (check_orient(words[2]) != 1)
		return (err_clean_table(words, 75));
	width = atof(words[3]);
	height = atof(words[4]);
	if (width < 0 || is_not_float(words[3]))
		return (err_clean_table(words, 73));
	if (height < 0 || is_not_float(words[4]))
		return (err_clean_table(words, 73));
	return (1);
}
