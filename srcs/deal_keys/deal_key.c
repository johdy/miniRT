/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:29:38 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 13:29:40 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_elem(int key, t_obj *obj)
{
	if (cannot_change(key, obj->label, 1))
		return ;
	if (key == N2_KEY || key == G_KEY)
		obj->orient.y -= OFFSET_ROT;
	if (key == N8_KEY || key == T_KEY)
		obj->orient.y += OFFSET_ROT;
	if (key == N4_KEY || key == R_KEY)
		obj->orient.x -= OFFSET_ROT;
	if (key == N6_KEY || key == Y_KEY)
		obj->orient.x += OFFSET_ROT;
	if (key == N1_KEY || key == V_KEY)
		obj->orient.z -= OFFSET_ROT;
	if (key == N7_KEY || key == B_KEY)
		obj->orient.z += OFFSET_ROT;
	obj->orient = cap_orient(obj->orient);
	if (ft_strncmp(obj->label, "cy", 2) == 0 && obj->fov == 1)
	{
		if (obj->next && ft_strncmp(obj->next->label, "cy", 2) == 0)
			rotate_elem(key, obj->next);
	}
}

void	ray_and_height(int key, t_obj *obj)
{
	if (cannot_change(key, obj->label, 0))
		return ;
	if (key == E_KEY)
		obj->ray += OFFSET;
	if (key == S_KEY)
		obj->ray -= OFFSET;
	if (key == X_KEY)
		obj->height += OFFSET;
	if (key == H_KEY)
		obj->height -= OFFSET;
	obj->ray = plancher_size(obj, obj->ray);
	obj->height = plancher_size(obj, obj->height);
	if (ft_strncmp(obj->label, "cy", 2) == 0 && obj->fov == 1)
	{
		if (obj->next && ft_strncmp(obj->next->label, "cy", 2) == 0)
			ray_and_height(key, obj->next);
	}
}

void	move_elem(int key, t_obj *obj)
{
	if (key == LEFT_KEY)
		obj->orig.x -= OFFSET;
	if (key == RIGHT_KEY)
		obj->orig.x += OFFSET;
	if (key == DOWN_KEY)
		obj->orig.y -= OFFSET;
	if (key == UP_KEY)
		obj->orig.y += OFFSET;
	if (key == F_KEY)
		obj->orig.z += OFFSET;
	if (key == C_KEY)
		obj->orig.z -= OFFSET;
	if (ft_strncmp(obj->label, "cy", 2) == 0 && obj->fov == 1)
	{
		if (obj->next && ft_strncmp(obj->next->label, "cy", 2) == 0)
			move_elem(key, obj->next);
	}
}

void	next_elem_console(t_obj *list)
{
	int r;
	int a;

	clean_console(list->mlx);
	while (a || r)
	{
		if (ft_strncmp(list->currelem->label, "cy", 2) == 0)
		{
			if (list->currelem->next->next)
				list->currelem = list->currelem->next->next;
			else
				list->currelem = list;
		}
		else if (list->currelem->next)
			list->currelem = list->currelem->next;
		else
			list->currelem = list;
		a = (ft_strncmp(list->currelem->label, "A", 1) == 0);
		r = (ft_strncmp(list->currelem->label, "R", 1) == 0);
	}
	manage_console(&list);
}

int		deal_key(int key, t_obj *list)
{
	t_mlx	mlx;
	t_obj	*res;
	char	*title;

	if (key == U_KEY)
		list = ft_switch_cam(&list);
	else if (key == N_KEY)
	{
		next_elem_console(list);
		return (0);
	}
	else if (key == E_KEY || key == S_KEY || key == X_KEY || key == H_KEY)
		ray_and_height(key, list->currelem);
	else if (key == LEFT_KEY || key == UP_KEY || key == DOWN_KEY)
		move_elem(key, list->currelem);
	else if (key == F_KEY || key == C_KEY || key == RIGHT_KEY)
		move_elem(key, list->currelem);
	else if ((key >= N1_KEY && key <= N8_KEY) || key == G_KEY || key == T_KEY)
		rotate_elem(key, list->currelem);
	else if (key == R_KEY || key == Y_KEY || key == V_KEY || key == B_KEY)
		rotate_elem(key, list->currelem);
	escapp(key, list);
	compute_wdw(list->mlx, &list, lookfor(&list, "R"), NULL);
	return (0);
}
