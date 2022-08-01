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

void	print_help(t_obj **list, int welcome)
{
	ft_putstr_fd("////////////////////////////////////////////\n", 1);
	ft_putstr_fd("E : Augmenter le rayon de l'element courant.\n", 1);
	ft_putstr_fd("S : Diminuer le rayon de l'element courant.\n", 1);
	ft_putstr_fd("X : Augmenter la hauteur du cylindre.\n", 1);
	ft_putstr_fd("M : Diminuer la hauteur du cylindre.\n", 1);
	ft_putstr_fd("U : Changer de camera.\n", 1);
	ft_putstr_fd("P : modifier l'offset general.\n", 1);
	ft_putstr_fd("O : modifier l'orientation de l'objet courant.\n", 1);
	ft_putstr_fd("Utiliser les fleches ainsi que F et C ", 1);
	ft_putstr_fd("pour bouger l'element courant.\n", 1);
	ft_putstr_fd("T, G, R, Y, V, B ", 1);
	ft_putstr_fd("pour faire une rotation de l'element courant.\n", 1);
	ft_putstr_fd("N : changer d'element courant.\n", 1);
	ft_putstr_fd("H : Faire reapparaitre ce message.\n", 1);
	ft_putstr_fd("////////////////////////////////////////////\n", 1);
	if (!welcome)
		manage_console(list);
}

int		escape_key(int key, t_obj *list)
{
	if (key == ESCAPE)
		exit(0);
	return (0);
}

int		manage_console(t_obj **list)
{
	t_obj *obj;

	obj = (*list)->currelem;
	if (ft_strncmp(obj->label, "sp", ft_strlen(obj->label)) == 0)
		ft_putstr_fd("Element courant : Sphere.\n", 1);
	else if (ft_strncmp(obj->label, "c", ft_strlen(obj->label)) == 0)
		ft_putstr_fd("Element courant : Camera.\n", 1);
	else if (ft_strncmp(obj->label, "l", ft_strlen(obj->label)) == 0)
		ft_putstr_fd("Element courant : Lumiere.\n", 1);
	else if (ft_strncmp(obj->label, "cy", 2) == 0)
		ft_putstr_fd("Element courant : Cylindre.\n", 1);
	else if (ft_strncmp(obj->label, "sq", ft_strlen(obj->label)) == 0)
		ft_putstr_fd("Element courant : Carre.\n", 1);
	else if (ft_strncmp(obj->label, "pl", ft_strlen(obj->label)) == 0)
		ft_putstr_fd("Element courant : Plan.\n", 1);
	else if (ft_strncmp(obj->label, "tr", ft_strlen(obj->label)) == 0)
		ft_putstr_fd("Element courant : Triangle.\n", 1);
	else
	{
		(*list)->currelem = obj->next;
		manage_console(list);
	}
	return (1);
}
