/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:11:56 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 13:11:59 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error_1(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nIl manque des arguments.\n", 1);
}

void	print_error_2(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nUn tuple est incorrect.\n", 1);
}

void	print_error_3(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nUn parametre est incorrect.\n", 1);
}

void	print_error_4(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nLa couleur est incorrecte.\n", 1);
}

void	print_error_5(int code)
{
	ft_putstr_fd("Erreur numero ", 1);
	ft_putnbr_fd(code, 1);
	ft_putstr_fd(" :\nL'orientation est incorrecte.\n", 1);
}
