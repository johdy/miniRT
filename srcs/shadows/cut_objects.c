/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:58:57 by jdyer             #+#    #+#             */
/*   Updated: 2020/09/16 15:59:17 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	cut_triangle(double t, t_vecs eye, t_vector norm, t_obj *tr)
{
	t_vector hitpoint;
	t_vector edge;
	t_vector c;

	hitpoint = addvector(eye.v1, multvector(eye.v2, t));
	edge = subvector(tr->b, tr->a);
	c = cross_prod(edge, subvector(hitpoint, tr->a));
	if (scalaire(norm, c) < 0 - E)
		return (1);
	edge = subvector(tr->c, tr->b);
	c = cross_prod(edge, subvector(hitpoint, tr->b));
	if (scalaire(norm, c) < 0 - E)
		return (1);
	edge = subvector(tr->a, tr->c);
	c = cross_prod(edge, subvector(hitpoint, tr->c));
	if (scalaire(norm, c) < 0 - E)
		return (1);
	return (t);
}

double	cut_square(double t, t_vecs eye, t_vector norm, t_obj *sq)
{
	t_obj		tr;
	t_vector	right;
	t_vector	far;
	t_vector	edge;
	int			ret;

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
	ret = cut_triangle(t, eye, norm, &tr);
	if (ret == 1)
		return (1);
	tr.a = tr.b;
	tr.b = addvector(tr.a, multvector(right, -sq->ray));
	ret = cut_triangle(t, eye, norm, &tr);
	return (ret);
}

double	cut_cy_sh(t_obj *cy, t_vector t, t_vector o_r, t_vector dir)
{
	t_vector	hitpoint;
	int			is_x_btw;
	int			is_y_btw;
	t_vecs		eye;

	eye.v1 = o_r;
	eye.v2 = get_normalized(dir);
	hitpoint = addvector(eye.v1, multvector(eye.v2, t.x));
	is_x_btw = is_btw_pl(cy, hitpoint);
	hitpoint = addvector(eye.v1, multvector(eye.v2, t.y));
	is_y_btw = is_btw_pl(cy, hitpoint);
	if (is_x_btw && is_y_btw)
		return (maxpos(t.x, t.y));
	else if (is_x_btw)
		return (t.x);
	else if (is_y_btw)
		return (t.y);
	else
		return (1);
}
