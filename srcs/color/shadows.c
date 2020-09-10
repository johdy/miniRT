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
	if (new_dist < 0)
		new_dist = new_dist * new_dist;
	else
		return (old_dist);
	if (new_dist < 0 + E)
		return (old_dist);
	if (new_dist < old_dist)
		return (new_dist);
	return (old_dist);
}

int		no_shadows(t_obj **lst, t_vector hitpoint, t_vector light_orig)
{
	t_obj		*elem;
	t_hit		retprov;
	t_hit		ret;
	double		dist_points;
	t_vecs		incidence;

	ret = empty_ret();
	dist_points = norm2((subvector(hitpoint, light_orig)));
	incidence.v1 = hitpoint;
	incidence.v2 = get_normalized(subvector(hitpoint, light_orig));
	elem = *lst;
	while (elem)
	{
		retprov = what_would_it_hit(incidence, lst, elem, 0);
		if (ret.dist < 0 + E && retprov.dist < 0)
			ret.dist = retprov.dist * retprov.dist;
		else
			ret.dist = compare_ret(ret.dist, retprov.dist);
		elem = elem->next;
	}
	if (ret.dist < 0 + E)
		return (1);
	return (ret.dist > dist_points + E * dist_points ? 1 : 0);
}
