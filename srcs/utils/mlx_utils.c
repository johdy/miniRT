/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:00:22 by jdyer             #+#    #+#             */
/*   Updated: 2020/09/16 16:00:35 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		clickescape(t_obj *list)
{
	exit(0);
	return (0);
}

int		deal_expose_wdw(t_obj **list)
{
	compute_wdw((*list)->mlx, list, lookfor(list, "R"), 0);
	return (1);
}

void	init_list(t_obj *list, t_mlx *mlx)
{
	int i;

	i = 0;
	list->mlx = mlx;
	list->change_off = 0;
	list->change_rot = 0;
	list->offset = 5;
	while (i < 20)
	{
		list->off[i] = '\0';
		list->rot[i] = '\0';
		i++;
	}
}

void	hook_and_loop_mlx(t_obj *list)
{
	if (APPLE)
		compute_wdw(list->mlx, &list, lookfor(&list, "R"), 0);
	mlx_expose_hook(list->mlx->wdw, deal_expose_wdw, &list);
	mlx_key_hook(list->mlx->wdw, deal_key, list);
	mlx_hook(list->mlx->wdw, CLOSE, 1L << 17, clickescape, list);
	mlx_loop(list->mlx->ptr);
}
