/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:48:05 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 11:48:11 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		*ft_rvb(int color)
{
	int *rvb;

	if (!(rvb = malloc(sizeof(int) * 3)))
		return (NULL);
	rvb[0] = color / (256 * 256);
	color = color - (rvb[0] * 256 * 256);
	rvb[1] = color / 256;
	rvb[2] = color - (rvb[1] * 256);
	return (rvb);
}

double	*cap_intensity(double *intens_l, double amb)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (intens_l[i] > 1 - amb)
			intens_l[i] = 1 - amb;
		else if (intens_l[i] < 0)
			intens_l[i] = 0;
		i++;
	}
	return (intens_l);
}

int		define_color(double *intens_l, int color, double amb)
{
	int ret;
	int *rvb;
	int i;

	intens_l = cap_intensity(intens_l, amb);
	if (!(rvb = ft_rvb(color)))
	{
		free(intens_l);
		return (-1);
	}
	rvb[0] = rvb[0] * (intens_l[0] + amb);
	rvb[1] = rvb[1] * (intens_l[1] + amb);
	rvb[2] = rvb[2] * (intens_l[2] + amb);
	ret = 256 * 256 * rvb[0] + 256 * rvb[1] + rvb[2];
	free(rvb);
	free(intens_l);
	return (ret);
}

t_hit	define_point_color(t_hit ret, t_obj **lst, t_obj *obj, t_vector hp)
{
	double *light_intensity;
	double amb;

	if (!(light_intensity = light_addition(lst, obj, hp)))
		return (empty_ret());
	amb = lookfor(lst, "A")->intens;
	ret.color = define_color(light_intensity, obj->color, amb);
	if (ret.color == -1)
		return (empty_ret());
	return (ret);
}
