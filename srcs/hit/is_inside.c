/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:06:10 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 15:06:12 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	is_inside_triangle(double t, t_vecs eye, t_vector norm, t_obj *tr)
{
	t_vector hitpoint;
	t_vector edge;
	t_vector c;

	hitpoint = addvector(eye.v1, multvector(eye.v2, t));
	edge = subvector(tr->b, tr->a);
	c = cross_prod(edge, subvector(hitpoint, tr->a));
	if (scalaire(norm, c) < 0 - E)
		return (0);
	edge = subvector(tr->c, tr->b);
	c = cross_prod(edge, subvector(hitpoint, tr->b));
	if (scalaire(norm, c) < 0 - E)
		return (0);
	edge = subvector(tr->a, tr->c);
	c = cross_prod(edge, subvector(hitpoint, tr->c));
	if (scalaire(norm, c) < 0 - E)
		return (0);
	return (t);
}

double	is_inside_square(double t, t_vecs eye, t_vector norm, t_obj *sq)
{
	t_obj		tr;
	t_vector	right;
	t_vector	far;
	t_vector	edge;
	double		ret;

	far.x = 0;
	far.y = 0;
	far.z = 1;
	right = is_straight(norm, far);
	far = is_flat(right, norm, 1);
	tr.a = addvector(sq->orig, multvector(right, sq->ray / 2));
	tr.b = addvector(tr.a, multvector(far, -sq->ray / 2));
	tr.a = addvector(tr.a, multvector(far, sq->ray / 2));
	tr.c = addvector(sq->orig, multvector(far, sq->ray / 2));
	tr.c = addvector(tr.c, multvector(right, -sq->ray / 2));
	ret = is_inside_triangle(t, eye, norm, &tr);
	if (ret > 0 + E || ret < 0 - E)
		return (ret);
	tr.a = tr.b;
	tr.b = addvector(tr.a, multvector(right, -sq->ray));
	ret = is_inside_triangle(t, eye, norm, &tr);
	return (ret);
}

int		is_btw_pl(t_obj *cy, t_vector hitpoint)
{
	t_obj		pl;
	double		t;
	t_vector	n_orient;

	pl.orient = cy->orient;
	pl.orig = cy->orig;
	t = hit_plane(hitpoint, get_normalized(subvector(cy->orig, hitpoint)), &pl);
	if (t < 0 - E)
		return (1);
	n_orient = get_normalized(cy->orient);
	pl.orig = addvector(cy->orig, multvector(n_orient, -cy->height));
	t = hit_plane(hitpoint, get_normalized(subvector(cy->orig, hitpoint)), &pl);
	if (t < 0 - E)
		return (1);
	return (0);
}

double	cut_cylinder(t_obj *cy, t_vector t, t_vecs eye, int calc_col)
{
	t_vector	hitpoint;
	int			is_x_btw;
	int			is_y_btw;

	hitpoint = addvector(eye.v1, multvector(eye.v2, t.x));
	is_x_btw = is_btw_pl(cy, hitpoint);
	hitpoint = addvector(eye.v1, multvector(eye.v2, t.y));
	is_y_btw = is_btw_pl(cy, hitpoint);
	if (is_x_btw && is_y_btw && calc_col)
		return (minpos(t.x, t.y));
	else if (is_x_btw && is_y_btw)
		return (maxpos(t.x, t.y));
	else if (is_x_btw)
		return (t.x);
	else if (is_y_btw)
		return (t.y);
	else
		return (0);
}
