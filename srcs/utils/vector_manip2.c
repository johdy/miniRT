/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_manip2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:27:25 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:27:26 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		scalaire(t_vector vec1, t_vector vec2)
{
	return (0.5 * (norm2(vec1) + norm2(vec2) - norm2(subvector(vec1, vec2))));
}

t_vector	project(t_vector a, t_vector b)
{
	t_vector ret;

	ret = multvector(b, scalaire(a, b) / scalaire(b, b));
	return (ret);
}

t_vector	get_normalized(t_vector vec)
{
	return (multvector(vec, (1 / sqrt(norm2(vec)))));
}

t_vector	is_flat(t_vector up, t_vector dir, int tr)
{
	t_vector ret;

	if (dir.x == 0 && dir.y == 1 && dir.z == 0)
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 1;
	}
	else if (dir.x == 0 && dir.y == -1 && dir.z == 0)
	{
		ret.x = 0;
		ret.y = 0;
		if (tr)
			ret.z = 1;
		else
			ret.z = -1;
	}
	else
		ret = get_normalized(cross_prod(up, dir));
	return (ret);
}

t_vector	is_straight(t_vector norm, t_vector far)
{
	t_vector ret;

	if (norm.x == 0 && norm.y == 0 && norm.z == 1)
	{
		ret.x = 1;
		ret.y = 0;
		ret.z = 0;
	}
	else if (norm.x == 0 && norm.y == 0 && norm.z == -1)
	{
		ret.x = -1;
		ret.y = 0;
		ret.z = 0;
	}
	else
		ret = get_normalized(cross_prod(norm, far));
	return (ret);
}
