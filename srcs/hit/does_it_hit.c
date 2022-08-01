/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_it_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:31:24 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 14:31:26 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	deal_cylinder(t_vecs eye, t_obj **lst, t_obj *elem)
{
	t_vector	t;
	double		ret;

	if (elem->ray == 0 || elem->height == 0)
		return (0);
	t = hit_cylinder(eye.v1, eye.v2, lst, elem);
	if (t.x == 0 && t.y == 0)
		ret = 0;
	else
		ret = cut_cylinder(elem, t, eye);
	return (ret);
}

double	deal_sphere(t_vecs eye, t_obj **lst, t_obj *elem)
{
	t_vector	t;
	double		ret;

	t = hit_sphere(eye.v1, eye.v2, lst, elem);
	ret = minpos(t.x, t.y);
	return (ret);
}

t_hit	what_would_it_hit(t_vecs eye, t_obj **lst, t_obj *elem)
{
	t_hit		ret;
	t_vector	t;
	t_vector	hitpoint;

	ret = empty_ret();
	if (ft_strncmp(elem->label, "sp", ft_strlen(elem->label)) == 0)
		ret.dist = deal_sphere(eye, lst, elem);
	if (ft_strncmp(elem->label, "pl", ft_strlen(elem->label)) == 0)
		ret.dist = hit_plane(eye.v1, eye.v2, elem);
	if (ft_strncmp(elem->label, "tr", ft_strlen(elem->label)) == 0)
		ret.dist = hit_triangle(eye.v1, eye.v2, lst, elem);
	if (ft_strncmp(elem->label, "sq", ft_strlen(elem->label)) == 0)
		ret.dist = hit_square(eye.v1, eye.v2, lst, elem);
	if (ft_strncmp(elem->label, "cy", 2) == 0)
		ret.dist = deal_cylinder(eye, lst, elem);
	if (ret.dist > 0)
	{
		hitpoint = addvector(eye.v1, multvector(eye.v2, ret.dist));
		ret = define_point_color(ret, lst, elem, hitpoint);
	}
	return (ret);
}

int		does_it_hit(t_vector px, t_obj **lst)
{
	t_obj	*elem;
	t_hit	retprov;
	t_hit	ret;
	t_vecs	eye;

	ret = empty_ret();
	elem = *lst;
	eye.v1 = lookfor(lst, "c")->orig;
	eye.v2 = get_normalized(px);
	while (elem)
	{
		retprov = what_would_it_hit(eye, lst, elem);
		if (retprov.dist > 0 + E)
		{
			if (retprov.dist < ret.dist + E || ret.dist == 0)
			{
				ret.color = retprov.color;
				ret.dist = retprov.dist;
			}
		}
		elem = elem->next;
	}
	return (ret.color);
}
