/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:22:42 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:22:43 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	minpos(double x, double y)
{
	if (x < 0 + E && y > 0 + E)
		return (y);
	if (x > 0 + E && y < 0 + E)
		return (x);
	if (x > y)
		return (y);
	else
		return (x);
}

double	maxpos(double x, double y)
{
	if (x >= 0 - E && y < 0 + E)
		return (y);
	if (x < 0 + E && y >= 0 - E)
		return (x);
	if (x < y)
		return (y);
	else
		return (x);
}
