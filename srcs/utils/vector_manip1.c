/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_manip1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:27:15 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:27:16 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		norm2(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_vector	cross_prod(t_vector v1, t_vector v2)
{
	t_vector	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

t_vector	subvector(t_vector vec1, t_vector vec2)
{
	t_vector ret;

	ret.x = vec1.x - vec2.x;
	ret.y = vec1.y - vec2.y;
	ret.z = vec1.z - vec2.z;
	return (ret);
}

t_vector	addvector(t_vector vec1, t_vector vec2)
{
	t_vector ret;

	ret.x = vec1.x + vec2.x;
	ret.y = vec1.y + vec2.y;
	ret.z = vec1.z + vec2.z;
	return (ret);
}

t_vector	multvector(t_vector vec1, double m)
{
	t_vector ret;

	ret.x = vec1.x * m;
	ret.y = vec1.y * m;
	ret.z = vec1.z * m;
	return (ret);
}
