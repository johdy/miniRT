/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_new_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:29:23 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 13:29:25 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			cannot_change(int key, char *lb, int rotation)
{
	if (ft_strncmp(lb, "l", 1) == 0)
		return (1);
	if (ft_strncmp(lb, "tr", 2) == 0)
		return (1);
	if (rotation && ft_strncmp(lb, "sp", 2) == 0)
		return (1);
	else if (rotation)
		return (0);
	if (ft_strncmp(lb, "cy", 2) != 0)
	{
		if (key == H_KEY || key == X_KEY)
			return (1);
	}
	if (ft_strncmp(lb, "c", 2) == 0)
		return (1);
	if (ft_strncmp(lb, "pl", 2) == 0)
		return (1);
	return (0);
}

t_vector	cap_orient(t_vector orient)
{
	orient.x = orient.x > 1 ? 1 : orient.x;
	orient.x = orient.x < -1 ? -1 : orient.x;
	orient.y = orient.y > 1 ? 1 : orient.y;
	orient.y = orient.y < -1 ? -1 : orient.y;
	orient.z = orient.z > 1 ? 1 : orient.z;
	orient.z = orient.z < -1 ? -1 : orient.z;
	return (orient);
}

double		plancher_size(t_obj *obj, double param)
{
	param = param <= 0 ? 0 : param;
	return (param);
}

int			next_elem_console_and_help(t_obj *list, int key)
{
	int r;
	int a;

	a = 1;
	r = 1;
	if (key == H_KEY)
	{
		print_help(&list, 0);
		return (0);
	}
	while (a || r)
	{
		if (list->currelem->next)
			list->currelem = list->currelem->next;
		else
			list->currelem = list;
		a = (ft_strncmp(list->currelem->label, "A", 1) == 0);
		r = (ft_strncmp(list->currelem->label, "R", 1) == 0);
	}
	manage_console(&list);
	return (0);
}
