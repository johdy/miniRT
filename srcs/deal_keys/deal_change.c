#include "minirt.h"

void	print_error(void)
{
	printf("There was an error\n");
}

void	print_welcome(int key)
{
	if (key == P_KEY)
		printf("Début de la modification de l'offset\n");
	if (key == O_KEY)
		printf("Début de la modification de l'orientation\n");
}

char	get_number_pressed(int key)
{
	if (key == UP0_KEY)
		return ('0');
	if (key == UP1_KEY)
		return ('1');
	if (key == UP2_KEY)
		return ('2');
	if (key == UP3_KEY)
		return ('3');
	if (key == UP4_KEY)
		return ('4');
	if (key == UP5_KEY)
		return ('5');
	if (key == UP6_KEY)
		return ('6');
	if (key == UP7_KEY)
		return ('7');
	if (key == UP8_KEY)
		return ('8');
	if (key == UP9_KEY)
		return ('9');
	if (key == DOT_KEY)
		return ('.');
}

void	add_rot(int key, t_obj *list)
{
	int i;

	i = 0;
	while (list->rot[i])
		i++;
	if (i >= 20)
	{
		printf("Nombre de chiffre maximal atteint\n");
		return ;
	}
	list->rot[i] = get_number_pressed(key);
	if (key == COMA_KEY)
		list->rot[i] = ',';
	if (key == MINUS_KEY)
		list->rot[i] = '-';
	printf("%s\n",list->rot);
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
		printf("Nombre de chiffre maximal atteint\n");
		return ;
	}
	list->off[i] = get_number_pressed(key);
	printf("%s\n",list->off);
	return ;
}

void	flush_rot(t_obj *list, int esc)
{
	int i;
	double *orient;
	int check;

	check = 0;
	i = 0;
	if (esc == 0)
		printf("Modification annulée\n");
	else if (ft_strlen(list->rot) == 0)
		print_error();
	else if (check_tuple(list->rot) != 1)
		print_error();
	else if (check_orient(list->rot) != 1)
		print_error();
	else
	{
		printf("La nouvelle orientation de l'objet est : %f\n",list->rot);
		orient = read_tuple(list->rot);
		list->currelem->orient = fill_vector(list->currelem->orient, orient);
		if (ft_strncmp(list->currelem->label, "cy", 2) == 0 && list->currelem->fov == 1)
		{
			orient = read_tuple(list->rot);
			list->currelem->next->orient = fill_vector(list->currelem->next->orient, orient);
		}
		check = 1;
	}
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
		printf("Modification annulée\n");
	else if (ft_strlen(list->off) == 0)
		print_error();
	else if (is_not_float(list->off))
		print_error();
	else
		list->offset = atof(list->off);
	while (list->off[i])
		list->off[i++] = '\0';
	printf("Le nouvel offset est de : %f\n",list->offset);
	return ;
}

int		deal_change(int key, t_obj *list)
{
	print_welcome(key);
	if (key == P_KEY)
		list->change_off = 1;
	else if (key == O_KEY)
		list->change_rot = 1;
	else if (list->change_rot == 1)
		add_rot(key, list);
	else if (list->change_off == 1)
		add_off(key, list);
	if (key == ENTER || key == ESCAPE)
	{
		if (list->change_off == 1)
			flush_off(list, key - ESCAPE);
		else
			flush_rot(list, key - ESCAPE);
		list->change_off = 0;
		list->change_rot = 0;
	}
	return (1);
}