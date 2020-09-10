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
