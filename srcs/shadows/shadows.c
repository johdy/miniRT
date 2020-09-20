/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:14:32 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 13:14:35 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	compare_ret(double old_dist, double new_dist)
{
	// printf("ret compared\n");
	if (new_dist < 0)
		new_dist = new_dist * new_dist;
	else
		return (old_dist);
	if (old_dist == -1)
		return (new_dist);
	if (new_dist < old_dist)
		return (new_dist);
	return (old_dist);
}

double	does_it_touch(t_vecs eye, t_obj *elem)
{
	t_vector t;

	if (ft_strncmp(elem->label, "sp", ft_strlen(elem->label)) == 0)
	{
		t = touch_sphere(eye.v1, eye.v2, elem);
		if (t.z == 1)
			return (1);
		return (maxpos(t.x, t.y));
	}
	if (ft_strncmp(elem->label, "pl", ft_strlen(elem->label)) == 0)
		return (touch_plane(eye.v1, eye.v2, elem));
	if (ft_strncmp(elem->label, "tr", ft_strlen(elem->label)) == 0)
		return (touch_triangle(eye.v1, eye.v2, elem));
	if (ft_strncmp(elem->label, "sq", ft_strlen(elem->label)) == 0)
		return (touch_square(eye.v1, eye.v2, elem));
	if (ft_strncmp(elem->label, "cy", 2) == 0)
		return(touch_cylinder(eye.v1, eye.v2, elem));
	return (1);	
}

int		no_shadows(t_obj **lst, t_vector hitpoint, t_vector light_orig)
{
	t_obj		*elem;
	double		retprov;
	double		ret;
	double		dist_points;
	t_vecs		incidence;
	int			dummy;

	dummy = 0;
	ret = -1;
	dist_points = norm2((subvector(hitpoint, light_orig)));
	incidence.v1 = hitpoint;
	incidence.v2 = get_normalized(subvector(hitpoint, light_orig));
	elem = *lst;
	while (elem)
	{
		retprov = does_it_touch(incidence, elem);
		if (retprov < 0 + E && retprov > 0 - E && dummy == 0)
			dummy = 1;
		else if (retprov < 0 + E && retprov > 0 - E && dummy == 1)
		{
			ret = 0;
		}
		else
			ret = compare_ret(ret, retprov);
		elem = elem->next;

	}
	if (ret == -1)
		return (1);
	return (ret > dist_points + E * dist_points ? 1 : 0);
}
