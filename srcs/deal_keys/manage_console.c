/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_console.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:30:03 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 13:30:08 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_console(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < 300)
	{
		j = 0;
		while (j < 150)
		{
			mlx_pixel_put(mlx->ptr, mlx->cons, i, j, 0);
			j++;
		}
		i++;
	}
}

void	console_l(t_obj **list, t_obj *obj)
{
	t_mlx *mlx;

	mlx = (*list)->mlx;
	mlx_string_put(mlx->ptr, mlx->cons, 10, 0 + DEC, WH, obj->label);
	mlx_string_put(mlx->ptr, mlx->cons, 10, 60 + DEC, WH, "<");
	mlx_string_put(mlx->ptr, mlx->cons, 75, 60 + DEC, WH, ">");
	mlx_string_put(mlx->ptr, mlx->cons, 30, 60 + DEC, WH, "Down");
	mlx_string_put(mlx->ptr, mlx->cons, 37, 40 + DEC, WH, "Up");
	mlx_string_put(mlx->ptr, mlx->cons, 120, 10 + DEC, WH, "f : further");
	mlx_string_put(mlx->ptr, mlx->cons, 120, 25 + DEC, WH, "c : closer");
	mlx_string_put(mlx->ptr, mlx->cons, 10, 120 + DEC, WH, "n : next");
	mlx_string_put(mlx->ptr, mlx->cons, 150, 120 + DEC, WH, "u : change cam");
}

void	console_c(t_obj **list, t_obj *obj)
{
	t_mlx *mlx;

	mlx = (*list)->mlx;
	mlx_string_put(mlx->ptr, mlx->cons, 10, 0 + DEC, WH, obj->label);
	mlx_string_put(mlx->ptr, mlx->cons, 10, 60 + DEC, WH, "<");
	mlx_string_put(mlx->ptr, mlx->cons, 75, 60 + DEC, WH, ">");
	mlx_string_put(mlx->ptr, mlx->cons, 30, 60 + DEC, WH, "Down");
	mlx_string_put(mlx->ptr, mlx->cons, 37, 40 + DEC, WH, "Up");
	mlx_string_put(mlx->ptr, mlx->cons, 120, 10 + DEC, WH, "f : further");
	mlx_string_put(mlx->ptr, mlx->cons, 120, 25 + DEC, WH, "c : closer");
	mlx_string_put(mlx->ptr, mlx->cons, 10, 120 + DEC, WH, "n : next");
	mlx_string_put(mlx->ptr, mlx->cons, 150, 120 + DEC, WH, "u : change cam");
}

void	console_sp(t_obj **list, t_obj *obj)
{
	t_mlx *mlx;

	mlx = (*list)->mlx;
	mlx_string_put(mlx->ptr, mlx->cons, 10, 0 + DEC, WH, obj->label);
	mlx_string_put(mlx->ptr, mlx->cons, 10, 60 + DEC, WH, "<");
	mlx_string_put(mlx->ptr, mlx->cons, 75, 60 + DEC, WH, ">");
	mlx_string_put(mlx->ptr, mlx->cons, 30, 60 + DEC, WH, "Down");
	mlx_string_put(mlx->ptr, mlx->cons, 37, 40 + DEC, WH, "Up");
	mlx_string_put(mlx->ptr, mlx->cons, 120, 10 + DEC, WH, "f : further");
	mlx_string_put(mlx->ptr, mlx->cons, 120, 25 + DEC, WH, "c : closer");
	mlx_string_put(mlx->ptr, mlx->cons, 83, 80 + DEC, WH, "e : expand");
	mlx_string_put(mlx->ptr, mlx->cons, 83, 95 + DEC, WH, "s : shrink");
	mlx_string_put(mlx->ptr, mlx->cons, 10, 120 + DEC, WH, "n : next");
	mlx_string_put(mlx->ptr, mlx->cons, 150, 120 + DEC, WH, "u : change cam");
}

int		manage_console(t_obj **list)
{
	t_obj *obj;

	obj = (*list)->currelem;
	clean_console((*list)->mlx);
	if (ft_strncmp(obj->label, "sp", ft_strlen(obj->label)) == 0)
		console_sp(list, obj);
	else if (ft_strncmp(obj->label, "c", ft_strlen(obj->label)) == 0)
		console_c(list, obj);
	else if (ft_strncmp(obj->label, "l", ft_strlen(obj->label)) == 0)
		console_l(list, obj);
	else if (ft_strncmp(obj->label, "cy", 2) == 0)
		console_cy(list, obj);
	else if (ft_strncmp(obj->label, "sq", ft_strlen(obj->label)) == 0)
		console_sq(list, obj);
	else if (ft_strncmp(obj->label, "pl", ft_strlen(obj->label)) == 0)
		console_pl(list, obj);
	else if (ft_strncmp(obj->label, "tr", ft_strlen(obj->label)) == 0)
		console_tr(list, obj);
	else
	{
		(*list)->currelem = obj->next;
		manage_console(list);
	}
	return (1);
}
