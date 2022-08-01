/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_change_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:13:56 by jdyer             #+#    #+#             */
/*   Updated: 2020/09/14 16:14:14 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_change_error(void)
{
	ft_putstr_fd("La valeur entrée est incorrecte. ", 1);
	ft_putstr_fd("Modification annulée.\n", 1);
}

void	print_welcome(int key, t_obj *list)
{
	if (key == P_KEY && list->change_off == 0 && list->change_rot == 0)
		ft_putstr_fd("Début de la modification de l'offset.\n", 1);
	if (key == O_KEY && list->change_off == 0 && list->change_rot == 0)
	{
		if (cannot_change(key, list->currelem->label, 1) == 0)
			ft_putstr_fd("Début de la modification de l'orientation.\n", 1);
	}
}

char	get_number_pressed(int key)
{
	if (key == UP0_KEY || key == UP0_KEYA)
		return ('0');
	if (key == UP1_KEY || key == UP1_KEYA)
		return ('1');
	if (key == UP2_KEY || key == UP2_KEYA)
		return ('2');
	if (key == UP3_KEY || key == UP3_KEYA)
		return ('3');
	if (key == UP4_KEY || key == UP4_KEYA)
		return ('4');
	if (key == UP5_KEY || key == UP5_KEYA)
		return ('5');
	if (key == UP6_KEY || key == UP6_KEYA)
		return ('6');
	if (key == UP7_KEY || key == UP7_KEYA)
		return ('7');
	if (key == UP8_KEY || key == UP8_KEYA)
		return ('8');
	if (key == UP9_KEY || key == UP9_KEYA)
		return ('9');
	if (key == DOT_KEY || key == DOT_KEYA)
		return ('.');
	else
		return ('\0');
}

int		checkpoint_rot(t_obj *list)
{
	double *orient;

	ft_putstr_fd("La nouvelle orientation de l'objet est : ", 1);
	ft_putstr_fd(list->rot, 1);
	ft_putstr_fd("\n", 1);
	orient = read_tuple(list->rot, 1);
	list->currelem->orient = fill_vector(list->currelem->orient, orient);
	return (1);
}
