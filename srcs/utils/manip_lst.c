/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:16:53 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:16:54 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		bindcams(t_obj **lst, t_obj *cam1)
{
	t_obj *camlast;

	camlast = lookfor(lst, "c");
	while (camlast->nextcam)
		camlast = camlast->nextcam;
	camlast->nextcam = cam1;
}

t_obj		*lookfor(t_obj **lst, char *label)
{
	t_obj *elem;

	elem = *lst;
	while (elem && ft_strncmp(elem->label, label, ft_strlen(elem->label)) != 0)
		elem = elem->next;
	return (elem);
}

void		ft_lstadd(t_obj **alst, t_obj *new, int front)
{
	t_obj *item;

	item = NULL;
	if (!alst)
		alst = &new;
	else if (front)
	{
		new->next = *alst;
		*alst = new;
	}
	else
	{
		if (*alst)
			item = *alst;
		else
		{
			*alst = new;
			return ;
		}
		while (item->next)
			item = item->next;
		item->next = new;
	}
}

t_obj		*ft_switch_cam(t_obj **lst)
{
	t_obj *first_elem;
	t_obj *item;
	t_obj *cam_next;

	first_elem = *lst;
	if (ft_strncmp(first_elem->currelem->label, "c", 2) == 0)
		first_elem->currelem = first_elem->currelem->nextcam;
	if (ft_strncmp(first_elem->label, "c", 2) == 0)
	{
		first_elem->nextcam->next = first_elem->next;
		first_elem->nextcam->mlx = first_elem->mlx;
		return (first_elem->nextcam);
	}
	item = first_elem;
	while (ft_strncmp(item->next->label, "c", 2) != 0)
		item = item->next;
	cam_next = item->next->next;
	item->next = item->next->nextcam;
	item->next->next = cam_next;
	return (first_elem);
}

t_vector	fill_vector(t_vector vec, double *tab)
{
	vec.x = tab[0];
	vec.y = tab[1];
	vec.z = tab[2];
	free(tab);
	return (vec);
}
