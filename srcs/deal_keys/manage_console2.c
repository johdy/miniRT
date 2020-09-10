/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_console2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:30:17 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 13:30:20 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		escapp(int key, t_obj *list)
{
	if (key == ESCAPE)
		exit(0);
	return (0);
}

void	console_tr(t_obj **list, t_obj *obj)
{
	t_mlx *mlx;

	mlx = (*list)->mlx;
	mlx_string_put(mlx->ptr, mlx->cons, 10, 0 + DEC, WH, obj->label);
	mlx_string_put(mlx->ptr, mlx->cons, 10, 120 + DEC, WH, "n : next");
	mlx_string_put(mlx->ptr, mlx->cons, 150, 120 + DEC, WH, "u : change cam");
}

void	console_pl(t_obj **list, t_obj *obj)
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

void	console_sq(t_obj **list, t_obj *obj)
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

void	console_cy(t_obj **list, t_obj *obj)
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
	mlx_string_put(mlx->ptr, mlx->cons, 83, 80 + DEC, WH, "e / x : expand");
	mlx_string_put(mlx->ptr, mlx->cons, 83, 95 + DEC, WH, "s / h : shrink");
	mlx_string_put(mlx->ptr, mlx->cons, 10, 120 + DEC, WH, "n : next");
	mlx_string_put(mlx->ptr, mlx->cons, 150, 120 + DEC, WH, "u : change cam");
}
