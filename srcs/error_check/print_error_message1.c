/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:11:46 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:11:48 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		print_error_min10(void)
{
	ft_putstr_fd("Erreur numero -10 : Un malloc a échoué.\n", 1);
	return (-10);
}

void	print_error_min1(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nLe fichier n'existe pas ou n'est pas au format .rt\n", 1);
}

void	print_error_101(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nIl manque : ambiance / resolution / camera.\n", 1);
}

void	print_error_0(void)
{
	ft_putstr_fd("Erreur numero 0 : Un identifiant n'a pas ete reconnu.\n", 1);
}

int		print_error_message(int code)
{
	if (code == 0)
		print_error_0();
	else if (code == -1)
		print_error_min1(code);
	else if (code == 101)
		print_error_101(code);
	else if (code % 10 == 1)
		print_error_1(code);
	else if (code % 10 == 2)
		print_error_2(code);
	else if (code % 10 == 3)
		print_error_3(code);
	else if (code % 10 == 4)
		print_error_4(code);
	else if (code % 10 == 5)
		print_error_5(code);
	else if (code == 98 || code == 99)
		print_error_98(code);
	else if (code == 100)
		print_error_100(code);
	else if (code % 10 == 0)
		print_error_10(code);
	return (code);
}
