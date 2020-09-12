/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_geom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:41:27 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 15:41:33 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*define_cy(char **words, int cyl)
{
	double	*coord;
	double	*orient;
	int		color;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	coord = read_tuple(words[1]);
	create->orig = fill_vector(create->orig, coord);
	orient = read_tuple(words[2]);
	create->orient = fill_vector(create->orient, orient);
	create->ray = ft_atof(words[3]);
	create->height = ft_atof(words[4]);
	create->color = atocol(words[5]);
	return (create);
}

t_obj	*define_sp(char **words)
{
	double	*coord;
	int		color;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	coord = read_tuple(words[1]);
	create->orig = fill_vector(create->orig, coord);
	create->ray = ft_atof(words[2]);
	create->color = atocol(words[3]);
	return (create);
}

t_obj	*define_pl(char **words)
{
	double	*coord;
	double	*orient;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	coord = read_tuple(words[1]);
	create->orig = fill_vector(create->orig, coord);
	orient = read_tuple(words[2]);
	create->orient = fill_vector(create->orient, orient);
	create->color = atocol(words[3]);
	return (create);
}

t_obj	*define_tr(char **words)
{
	double	*point;
	double	*orient;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	point = read_tuple(words[1]);
	create->a = fill_vector(create->a, point);
	point = read_tuple(words[2]);
	create->b = fill_vector(create->b, point);
	point = read_tuple(words[3]);
	create->c = fill_vector(create->c, point);
	create->color = atocol(words[4]);
	return (create);
}

t_obj	*define_sq(char **words)
{
	double	*coord;
	double	*orient;
	int		color;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	coord = read_tuple(words[1]);
	create->orig = fill_vector(create->orig, coord);
	orient = read_tuple(words[2]);
	create->orient = fill_vector(create->orient, orient);
	create->ray = ft_atof(words[3]);
	create->color = atocol(words[4]);
	return (create);
}
