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

int		rotate_elem(int key, t_obj *obj)
{
	if (cannot_change(key, obj->label, 1))
		return (0);
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
	return (1);
}

int		ray_and_height(int key, t_obj *obj, double offset)
{
	if (cannot_change(key, obj->label, 0))
		return (0);
	if (key == E_KEY)
		obj->ray += offset;
	if (key == S_KEY)
		obj->ray -= offset;
	if (key == X_KEY)
		obj->height += offset;
	if (key == M_KEY)
		obj->height -= offset;
	obj->ray = plancher_size(obj, obj->ray);
	obj->height = plancher_size(obj, obj->height);
	return (1);
}

int		move_elem(int key, t_obj *obj, double offset)
{
	if (ft_strncmp(obj->label, "tr", 2) == 0)
		return (0);
	if (key == LEFT_KEY)
		obj->orig.x -= offset;
	if (key == RIGHT_KEY)
		obj->orig.x += offset;
	if (key == DOWN_KEY)
		obj->orig.y -= offset;
	if (key == UP_KEY)
		obj->orig.y += offset;
	if (key == F_KEY)
		obj->orig.z += offset;
	if (key == C_KEY)
		obj->orig.z -= offset;
	return (1);
}

int		follow_up_deal_key(int key, t_obj *list)
{
	int check;

	check = 0;
	if (key == E_KEY || key == S_KEY || key == X_KEY || key == M_KEY)
		check = ray_and_height(key, list->currelem, list->offset);
	else if (key == LEFT_KEY || key == UP_KEY || key == DOWN_KEY)
		check = move_elem(key, list->currelem, list->offset);
	else if (key == F_KEY || key == C_KEY || key == RIGHT_KEY)
		check = move_elem(key, list->currelem, list->offset);
	else if ((key >= N1_KEY && key <= N8_KEY) || key == G_KEY || key == T_KEY)
		check = rotate_elem(key, list->currelem);
	else if (key == R_KEY || key == Y_KEY || key == V_KEY || key == B_KEY)
		check = rotate_elem(key, list->currelem);
	return (check);
}

int		deal_key(int key, t_obj *list)
{
	t_mlx	mlx;
	t_obj	*res;
	int		check;

	if (key == P_KEY || key == O_KEY || list->change_off || list->change_rot)
		return (deal_change(key, list));
	if (key == N_KEY || key == H_KEY)
		return (next_elem_console_and_help(list, key));
	if (key == U_KEY)
	{
		check = 1;
		list = ft_switch_cam(&list);
	}
	else
		check = follow_up_deal_key(key, list);
	escape_key(key, list);
	if (check)
		compute_wdw(list->mlx, &list, lookfor(&list, "R"), 0);
	return (0);
}
