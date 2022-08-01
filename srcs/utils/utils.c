/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:18:03 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:18:04 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cap_resolution(t_obj **lst, t_mlx *mlx)
{
	int		mdx;
	int		mdy;
	t_obj	*res;

	res = lookfor(lst, "R");
	if (MAX_DEFX == 0)
		mlx_get_screen_size(mlx->ptr, &mdx, &mdy);
	else
	{
		mdx = MAX_DEFX;
		mdy = MAX_DEFY;
	}
	res->width = res->width > mdx ? mdx : res->width;
	res->high = res->high > mdy ? mdy : res->high;
}

double	*read_tuple(char *word, int orient)
{
	double	*ret;
	char	**tuple;

	if (!(ret = malloc(sizeof(double) * 3)))
		return (NULL);
	tuple = NULL;
	tuple = split(word, ",");
	ret[0] = ft_atof(tuple[0]);
	ret[1] = ft_atof(tuple[1]);
	ret[2] = ft_atof(tuple[2]);
	if (ret[0] == 0 && ret[1] == 0 && ret[2] == 0 && orient)
	{
		ret[0] = 1;
		ret[1] = 1;
		ret[2] = 1;
	}
	delete_tab(tuple);
	return (ret);
}

int		atocol(char *col)
{
	double	*tuple;
	int		ret;

	if (!(tuple = read_tuple(col, 0)))
		return (0);
	ret = 256 * 256 * tuple[0] + 256 * tuple[1] + tuple[2];
	free(tuple);
	return (ret);
}

t_hit	empty_ret(void)
{
	t_hit ret;

	ret.dist = 0;
	ret.color = 0;
	return (ret);
}

void	delete_tab(char **words)
{
	int nbwords;

	nbwords = 0;
	while (words[nbwords])
		nbwords++;
	while (nbwords > 0)
		free(words[nbwords-- - 1]);
	free(words);
}
