/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:19:40 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:19:41 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	getdot(double ret, int i, const char *str)
{
	double	postdot;
	int		nbdec;

	nbdec = 0;
	postdot = 0;
	if (str[i] == '.')
		i++;
	else
		return (ret);
	while (str[i + nbdec] > 47 && str[i + nbdec] < 58)
	{
		postdot = postdot * 10;
		postdot = postdot + str[i + nbdec] - 48;
		nbdec++;
	}
	while (nbdec > 0)
	{
		postdot = postdot / 10;
		nbdec--;
	}
	return (ret + postdot);
}

double	ft_atof(const char *str)
{
	double	ret;
	int		i;
	double	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		ret = ret * 10;
		ret = ret + str[i] - 48;
		i++;
	}
	ret = getdot(ret, i, str);
	return (sign * ret);
}
