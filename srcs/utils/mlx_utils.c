#include "minirt.h"

int		clickescape(t_obj *list)
{
	exit(0);
	return (0);
}

int		deal_expose_wdw(t_obj **list)
{
	compute_wdw((*list)->mlx, list, lookfor(list, "R"), NULL);
	return (1);
}

int		deal_expose_cons(t_obj **list)
{
	manage_console(list);
	return (1);
}

void	init_list(t_obj *list, t_mlx *mlx)
{
	list->mlx = mlx;
	list->change_off = 0;
	list->change_rot = 0;
	list->offset = 5;
}

void	hook_and_loop_mlx(t_obj *list)
{
	mlx_expose_hook(list->mlx->wdw, deal_expose_wdw, &list);
	mlx_expose_hook(list->mlx->cons, deal_expose_cons, &list);
	mlx_key_hook(list->mlx->cons, deal_key, list);
	mlx_key_hook(list->mlx->wdw, escapp, list);
	mlx_hook(list->mlx->wdw, CLOSE, 1L << 0, clickescape, list);
	mlx_loop(list->mlx->ptr);	
}