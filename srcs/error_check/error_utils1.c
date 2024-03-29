/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:02:23 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:02:25 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_argv(int argc, char **argv)
{
	if (argc == 1)
	{
		print_error_no_args();
		return (0);
	}
	if (argc == 2)
		return (1);
	if (argc > 3)
		return (print_error_too_much_args(1));
	if (ft_strncmp(argv[2], "-save", 6) == 0)
		return (2);
	if (ft_strncmp(argv[2], "--save", 7) == 0)
		return (2);
	if (argc == 3)
		print_error_too_much_args(0);
	return (0);
}

int		err_clean_table(char **words, int err)
{
	delete_tab(words);
	return (err);
}

int		check_tuple(char *word)
{
	int i;
	int virg;

	i = 0;
	virg = 0;
	if (word[0] == ',')
		return (2);
	while (word[i])
	{
		if (ft_isdigit(word[i]) || word[i] == '.' || word[i] == '-')
			i++;
		else if (word[i] == ',')
		{
			if (word[i - 1] == ',')
				return (2);
			virg++;
			i++;
		}
		else
			return (2);
	}
	if (virg != 2 || word[i - 1] == ',' || check_float_pb(word) == 1)
		return (2);
	return (1);
}

int		check_color(char *word)
{
	int virg1;
	int virg2;
	int nb[3];
	int end;

	virg1 = 0;
	while (word[virg1] != ',' && word[virg1] != '.')
		virg1++;
	virg2 = virg1 + 1;
	while (word[virg2] != ',' && word[virg2] != '.')
		virg2++;
	end = virg2 + 1;
	while (word[end] && word[end] != '.')
		end++;
	if (word[virg1] == '.' || word[virg2] == '.' || word[end] == '.')
		return (4);
	nb[0] = ft_atoi(word);
	nb[1] = ft_atoi(word + virg1 + 1);
	nb[2] = ft_atoi(word + virg2 + 1);
	if (nb[0] < 0 || nb[1] < 0 || nb[2] < 0)
		return (4);
	if (nb[0] > 255 || nb[1] > 255 || nb[2] > 255)
		return (4);
	return (1);
}

int		check_orient(char *word)
{
	int		virg1;
	int		virg2;
	double	nb[3];

	virg1 = 0;
	while (word[virg1] != ',')
		virg1++;
	virg2 = virg1 + 1;
	while (word[virg2] != ',')
		virg2++;
	nb[0] = ft_atof(word);
	if (nb[0] < -1 || nb[0] > 1)
		return (5);
	nb[1] = ft_atof(word + virg1 + 1);
	if (nb[1] < -1 || nb[1] > 1)
		return (5);
	nb[2] = ft_atof(word + virg2 + 1);
	if (nb[2] < -1 || nb[2] > 1)
		return (5);
	return (1);
}
