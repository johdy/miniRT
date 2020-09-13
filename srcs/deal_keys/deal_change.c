#include "minirt.h"


void	add_rot(int key, t_obj *list)
{
	int i;

	i = 0;
	while (list->rot[i])
		i++;
	if (i >= 20)
	{
		ft_putstr_fd("Nombre maximal de chiffre atteint. ", 1);
		ft_putstr_fd("Veuillez appuyer sur ENTER ou ESCAPE. \n", 1);
		return ;
	}
	list->rot[i] = get_number_pressed(key);
	if (key == COMA_KEY)
		list->rot[i] = ',';
	if (key == MINUS_KEY)
		list->rot[i] = '-';
	if (list->rot[i] == '\0')
		return ;
	ft_putstr_fd("Orientation courante : ", 1);
	ft_putstr_fd(list->rot, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

void	add_off(int key, t_obj *list)
{
	int i;

	i = 0;
	while (list->off[i])
		i++;
	if (i >= 10)
	{
		ft_putstr_fd("Nombre maximal de chiffre atteint. ", 1);
		ft_putstr_fd("Veuillez appuyer sur ENTER ou ESCAPE. \n", 1);
		return ;
	}
	list->off[i] = get_number_pressed(key);
	if (list->off[i] == '\0')
		return ;
	ft_putstr_fd("Offset courant : ", 1);
	ft_putstr_fd(list->off, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

void	flush_rot(t_obj *list, int esc)
{
	int i;
	int check;

	check = 0;
	i = 0;
	if (esc == 0)
		ft_putstr_fd("Modification annulée.\n", 1);
	else if (ft_strlen(list->rot) == 0)
		print_change_error();
	else if (check_tuple(list->rot) != 1)
		print_change_error();
	else if (check_orient(list->rot) != 1)
		print_change_error();
	else
		check = checkpoint_rot(list);
	while (list->rot[i])
		list->rot[i++] = '\0';
	if (check == 1)
		compute_wdw(list->mlx, &list, lookfor(&list, "R"), NULL);
	return ;
}

void	flush_off(t_obj *list, int esc)
{
	int i;

	i = 0;
	if (esc == 0)
		ft_putstr_fd("Modification annulée.\n", 1);
	else if (ft_strlen(list->off) == 0)
		print_change_error();
	else if (is_not_float(list->off))
		print_change_error();
	else
	{
		ft_putstr_fd("Le nouvel offset est : ", 1);
		ft_putstr_fd(list->off, 1);
		ft_putstr_fd("\n", 1);
		list->offset = atof(list->off);
	}
	while (list->off[i])
		list->off[i++] = '\0';
	return ;
}

int		deal_change(int key, t_obj *list)
{
	print_welcome(key, list);
	if (key == P_KEY && list->change_rot == 0)
		list->change_off = 1;
	else if (key == O_KEY && list->change_off == 0 && cannot_change(key, list->currelem->label, 1) == 0)
		list->change_rot = 1;
	else if (key == ENTER || key == ESCAPE)
	{
		if (list->change_off == 1)
			flush_off(list, key - ESCAPE);
		else
			flush_rot(list, key - ESCAPE);
		list->change_off = 0;
		list->change_rot = 0;
	}
	else if (list->change_rot == 1)
		add_rot(key, list);
	else if (list->change_off == 1)
		add_off(key, list);
	return (1);
}
