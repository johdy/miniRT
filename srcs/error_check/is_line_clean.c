/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:02:57 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:02:58 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_l(char **words)
{
	double intens;

	if (!words[1] || !words[2] || !words[3])
		return (err_clean_table(words, 21));
	if (words[4])
		return (err_clean_table(words, 20));
	if (check_tuple(words[1]) == 2 || check_tuple(words[3]) == 2)
		return (err_clean_table(words, 22));
	if (check_color(words[3]) != 1)
		return (err_clean_table(words, 24));
	intens = atof(words[2]);
	if (intens < 0 || intens > 1 || is_not_float(words[2]))
		return (err_clean_table(words, 23));
	return (1);
}

int	check_c(char **words)
{
	double fov;

	if (!words[1] || !words[2] || !words[3])
		return (err_clean_table(words, 11));
	if (words[4])
		return (err_clean_table(words, 10));
	if (check_tuple(words[1]) == 2 || check_tuple(words[2]) == 2)
		return (err_clean_table(words, 12));
	if (check_orient(words[2]) != 1)
		return (err_clean_table(words, 15));
	fov = ft_atof(words[3]);
	if (fov < 0 || fov > 180 || is_not_float(words[3]))
		return (err_clean_table(words, 13));
	return (1);
}

int	check_r(char **words, t_majcount *ar)
{
	int x;
	int y;

	if (!words[1] || !words[2])
		return (err_clean_table(words, 91));
	if (words[3])
		return (err_clean_table(words, 90));
	if (ar->r > 0)
		return (err_clean_table(words, 99));
	if (is_not_int(words[1]) || is_not_int(words[2]))
		return (err_clean_table(words, 93));
	if (ft_atoi(words[1]) < 0 || ft_atoi(words[2]) < 0)
		return (err_clean_table(words, 100));
	ar->r++;
	return (1);
}

int	check_a(char **words, t_majcount *ar)
{
	double intens;

	if (!words[1] || !words[2])
		return (err_clean_table(words, 91));
	if (words[3])
		return (err_clean_table(words, 90));
	if (ar->a > 0)
		return (err_clean_table(words, 98));
	intens = atof(words[1]);
	if (intens < 0 + E || intens > 1 || is_not_float(words[1]))
		return (err_clean_table(words, 93));
	if (check_tuple(words[2]) != 1)
		return (err_clean_table(words, 92));
	if (check_color(words[2]) != 1)
		return (err_clean_table(words, 94));
	ar->a++;
	return (1);
}

int	is_line_clean(char **words, t_majcount *ar)
{
	if (ft_strncmp(words[0], "l", ft_strlen(words[0])) == 0)
		return (check_l(words));
	else if (ft_strncmp(words[0], "c", ft_strlen(words[0])) == 0)
		return (check_c(words));
	else if (ft_strncmp(words[0], "R", ft_strlen(words[0])) == 0)
		return (check_r(words, ar));
	else if (ft_strncmp(words[0], "A", ft_strlen(words[0])) == 0)
		return (check_a(words, ar));
	else if (ft_strncmp(words[0], "sp", ft_strlen(words[0])) == 0)
		return (check_sp(words));
	else if (ft_strncmp(words[0], "pl", ft_strlen(words[0])) == 0)
		return (check_pl(words));
	else if (ft_strncmp(words[0], "tr", ft_strlen(words[0])) == 0)
		return (check_tr(words));
	else if (ft_strncmp(words[0], "sq", ft_strlen(words[0])) == 0)
		return (check_sq(words));
	else if (ft_strncmp(words[0], "cy", 2) == 0)
		return (check_cy(words));
	else
		return (err_clean_table(words, 0));
}
