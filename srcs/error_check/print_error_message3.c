/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:12:05 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:12:06 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error_10(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nTrop de parametres declares.\n", 1);
}

void	print_error_100(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nLa resolution ne peut etre negative.\n", 1);
}

void	print_error_98(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nDouble declaration resolution / ambiance.\n", 1);
}

void	print_error_no_args(void)
{
	ft_putstr_fd("Erreur numero -2 :\n Il faut un argument.\n", 1);
	return ;
}

int		print_error_too_much_args(int too_much)
{
	if (too_much)
	{
		ft_putstr_fd("Erreur numero -4 :\n", 1);
		ft_putstr_fd("Il ne peut y avoir plus de 2 arguments.\n", 1);
	}
	else
	{
		ft_putstr_fd("Erreur numero -3 :\n", 1);
		ft_putstr_fd("S'il y a un second argument, ", 1);
		ft_putstr_fd("ce doit être -save ou --save.\n", 1);
	}
	return (0);
}
