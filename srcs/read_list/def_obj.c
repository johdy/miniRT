/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:38:24 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 15:38:25 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*define_a_r(char **words)
{
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	if (ft_strncmp(words[0], "R", ft_strlen(words[0])) == 0)
	{
		create->width = ft_atoi(words[1]);
		create->high = ft_atoi(words[2]);
		return (create);
	}
	create->intens = ft_atof(words[1]);
	create->color = atocol(words[2]);
	return (create);
}

t_obj	*define_l(char **words)
{
	double	*coord;
	int		color;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	if (!(coord = read_tuple(words[1])))
		return (NULL);
	create->orig = fill_vector(create->orig, coord);
	create->intens = ft_atof(words[2]);
	create->color = atocol(words[3]);
	return (create);
}

t_obj	*define_c(char **words)
{
	double	*coord;
	double	*orient;
	t_obj	*create;

	if ((create = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	create->label = ft_strdup(words[0]);
	coord = read_tuple(words[1]);
	orient = read_tuple(words[2]);
	if (!coord || !orient)
		return (NULL);
	create->orig = fill_vector(create->orig, coord);
	create->orient = fill_vector(create->orient, orient);
	create->nextcam = NULL;
	create->fov = ft_atof(words[3]);
	return (create);
}

t_obj	*def_geom(char **words)
{
	t_obj *create;

	if (ft_strncmp(words[0], "sp", ft_strlen(words[0])) == 0)
		create = define_sp(words);
	else if (ft_strncmp(words[0], "pl", ft_strlen(words[0])) == 0)
		create = define_pl(words);
	else if (ft_strncmp(words[0], "tr", ft_strlen(words[0])) == 0)
		create = define_tr(words);
	else if (ft_strncmp(words[0], "sq", ft_strlen(words[0])) == 0)
		create = define_sq(words);
	else if (ft_strncmp(words[0], "cy", 2) == 0)
		create = define_cy(words);
	return (create);
}

t_obj	*def_obj(char **words)
{
	t_obj *create;

	if (ft_strncmp(words[0], "l", ft_strlen(words[0])) == 0)
		create = define_l(words);
	else if (ft_strncmp(words[0], "c", ft_strlen(words[0])) == 0)
		create = define_c(words);
	else if (ft_strncmp(words[0], "R", ft_strlen(words[0])) == 0)
		create = define_a_r(words);
	else if (ft_strncmp(words[0], "A", ft_strlen(words[0])) == 0)
		create = define_a_r(words);
	else
		create = def_geom(words);
	delete_tab(words);
	create->next = NULL;
	return (create);
}
