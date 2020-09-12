/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:48:37 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 11:48:40 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normale_sp(t_vector orig_r, t_vector hitpoint, t_obj *sp)
{
	t_vector t;
	t_vector dir;

	dir = get_normalized(subvector(hitpoint, orig_r));
	t = hit_sphere(orig_r, dir, NULL, sp);
	if (t.x * t.y < 0)
		return (get_normalized(subvector(sp->orig, hitpoint)));
	else
		return (get_normalized(subvector(hitpoint, sp->orig)));
}

t_vector	normale_cy(t_vector hitpoint, t_obj *cy)
{
	t_vector v;

	v = subvector(hitpoint, cy->orig);
	v = subvector(v, project(v, cy->orient));
	if (cy->fov == 1)
	{
		v.x = -v.x;
		v.y = -v.y;
		v.z = -v.z;
	}
	return (get_normalized(v));
}

t_vector	compute_normale(t_vector hitpoint, t_obj *elem, t_vector orig_r)
{
	t_vector normale;
	t_vector traj;
	t_vector up;
	t_vector right;
	t_vector subv;

	subv = cross_prod(subvector(elem->b, elem->a), subvector(elem->c, elem->a));
	if (ft_strncmp(elem->label, "sp", ft_strlen(elem->label)) == 0)
		normale = normale_sp(orig_r, hitpoint, elem);
	else if (ft_strncmp(elem->label, "tr", ft_strlen(elem->label)) == 0)
		normale = get_normalized(subv);
	else if (ft_strncmp(elem->label, "cy", 2) == 0)
		normale = normale_cy(hitpoint, elem);
	else
		normale = get_normalized(elem->orient);
	return (normale);
}

double		*add_light(t_obj *light, t_vecs p_rvb, t_obj **lst)
{
	double		intens[2];
	double		max_intens;
	int			*light_rvb;
	t_vector	incidence;
	t_obj		*cam;

	cam = lookfor(lst, "c");
	light_rvb = ft_rvb(light->color);
	incidence = get_normalized(subvector(light->orig, p_rvb.v1));
	intens[0] = light->intens * scalaire(p_rvb.v2, incidence);
	if (intens[0] > 0 && scalaire(subvector(cam->orig, p_rvb.v1), p_rvb.v2) > 0)
		intens[0] = intens[0] * no_shadows(lst, p_rvb.v1, light->orig);
	else
		intens[0] = 0;
	p_rvb.v2.x = - p_rvb.v2.x;
	p_rvb.v2.y = - p_rvb.v2.y;
	p_rvb.v2.z = - p_rvb.v2.z;
	intens[1] = light->intens * scalaire(p_rvb.v2, incidence);
	if (intens[1] > 0 && scalaire(subvector(cam->orig, p_rvb.v1), p_rvb.v2) > 0)
		intens[1] = intens[1] * no_shadows(lst, p_rvb.v1, light->orig);
	else
		intens[1] = 0;
	if (intens[0] == 0)
		max_intens = intens[1];
	else
		max_intens = intens[0];
	p_rvb.intens_l[0] += max_intens * ((double)light_rvb[0] / 255);
	p_rvb.intens_l[1] += max_intens * ((double)light_rvb[1] / 255);
	p_rvb.intens_l[2] += max_intens * ((double)light_rvb[2] / 255);
	free(light_rvb);
	return (p_rvb.intens_l);
}

double		*light_addition(t_obj **lst, t_obj *obj, t_vector hitpoint)
{
	t_vecs		p_rvb;
	t_vector	normale;
	t_obj		*light;

	p_rvb.v1 = hitpoint;
	p_rvb.v2 = compute_normale(hitpoint, obj, lookfor(lst, "c")->orig);
	if (!(p_rvb.intens_l = malloc(sizeof(double) * 3)))
		return (NULL);
	p_rvb.intens_l[0] = 0;
	p_rvb.intens_l[1] = 0;
	p_rvb.intens_l[2] = 0;
	light = *lst;
	while (light)
	{
		while (light->next && ft_strncmp(light->label, "l", 1) != 0)
			light = light->next;
		if (ft_strncmp(light->label, "l", ft_strlen(light->label)) != 0)
			break ;
		p_rvb.intens_l = add_light(light, p_rvb, lst);
		if (light)
			light = light->next;
	}
	return (p_rvb.intens_l);
}
