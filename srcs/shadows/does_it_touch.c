/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_it_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:59:27 by jdyer             #+#    #+#             */
/*   Updated: 2020/09/16 15:59:42 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		touch_triangle(t_vector orig_r, t_vector dir, t_obj *tr)
{
	t_vector	norm;
	double		t;
	t_vecs		eye;
	t_vector	ab;

	ab = subvector(tr->b, tr->a);
	norm = get_normalized(cross_prod(ab, subvector(tr->c, tr->a)));
	t = scalaire(subvector(tr->a, orig_r), norm);
	eye.v1 = orig_r;
	eye.v2 = get_normalized(dir);
	if (scalaire(dir, norm) < 0 - E || scalaire(dir, norm) > 0 + E)
		t = t / scalaire(dir, norm);
	else
		return (1);
	t = cut_triangle(t, eye, norm, tr);
	return (t);
}

double		touch_square(t_vector orig_r, t_vector dir, t_obj *sq)
{
	t_vector	orient;
	double		t;
	t_vecs		eye;

	eye.v1 = orig_r;
	eye.v2 = get_normalized(dir);
	orient = get_normalized(sq->orient);
	t = scalaire(subvector(sq->orig, orig_r), orient);
	if (scalaire(dir, orient) < 0 - E || scalaire(dir, orient) > 0 + E)
		t = t / scalaire(dir, orient);
	else
		return (1);
	t = cut_square(t, eye, orient, sq);
	return (t);
}

double		touch_plane(t_vector orig_r, t_vector dir, t_obj *pl)
{
	t_vector	orient;
	double		t;

	orient = get_normalized(pl->orient);
	t = scalaire(subvector(pl->orig, orig_r), orient);
	if (scalaire(dir, orient) < 0 - E || scalaire(dir, orient) > 0 + E)
		t = t / scalaire(dir, orient);
	else
		return (1);
	return (t);
}

t_vector	touch_sphere(t_vector orig_r, t_vector dir, t_obj *sp)
{
	double		c;
	double		b;
	double		delta;
	t_vector	t;

	t.x = 0;
	t.y = 0;
	t.z = 0;
	c = norm2(subvector(orig_r, sp->orig)) - (sp->ray * sp->ray);
	b = 2 * scalaire(dir, subvector(orig_r, sp->orig));
	delta = (b * b) - (4 * norm2(dir) * c);
	if (delta < 0)
	{
		t.z = 1;
		return (t);
	}
	t.x = (-b + sqrt(delta)) / 2;
	t.y = (-b - sqrt(delta)) / 2;
	return (t);
}

double		touch_cylinder(t_vector orig_r, t_vector dir, t_obj *cy)
{
	t_vector	cperp;
	t_vector	pperp;
	t_vector	dperp;
	t_obj		sp;
	t_vector	t;

	cperp = project(cy->orig, cy->orient);
	cperp = subvector(cy->orig, cperp);
	pperp = project(orig_r, cy->orient);
	pperp = subvector(orig_r, pperp);
	dperp = project(dir, cy->orient);
	dperp = subvector(dir, dperp);
	sp.orig = cperp;
	sp.ray = cy->ray;
	t = touch_sphere(pperp, get_normalized(dperp), &sp);
	if (t.z == 1)
		return (1);
	t.x = t.x / sqrt(norm2(dperp));
	t.y = t.y / sqrt(norm2(dperp));
	return (cut_cy_sh(cy, t, orig_r, dir));
}
