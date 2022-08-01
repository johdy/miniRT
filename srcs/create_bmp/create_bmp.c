/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:15:49 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/22 13:15:53 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	copy_int_to_mem(char *where, int what)
{
	ft_memcpy(where, &what, 4);
}

void	write_header(int fd, int sizefile, t_obj *res)
{
	char header[54];

	ft_bzero(header, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[3] = (unsigned char)(1);
	copy_int_to_mem(header + 2, sizefile);
	copy_int_to_mem(header + 10, 54);
	copy_int_to_mem(header + 14, 40);
	copy_int_to_mem(header + 18, res->width);
	copy_int_to_mem(header + 22, res->high);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	copy_int_to_mem(header + 34, sizefile - 54);
	copy_int_to_mem(header + 38, 2834);
	copy_int_to_mem(header + 42, 2834);
	write(fd, header, 54);
}

int		*color_line(int px, int *tabint, t_obj *res, t_offset offs)
{
	int i;
	int j;
	int ind;
	int *color;

	i = 0;
	j = px / (res->width + offs.pad);
	ind = j * (offs.sl / 4);
	if (!(color = malloc(sizeof(int) * res->width)))
		return (NULL);
	while (i < res->width)
	{
		color[i] = tabint[ind + i];
		i++;
	}
	return (color);
}

int		write_image(int fd, int *tabint, t_obj *res, t_offset offs)
{
	int *color;
	int i;
	int m;
	int zero;

	zero = 0;
	m = 0;
	i = (res->high * (res->width + offs.pad)) - 1;
	while (i >= 0)
	{
		if (i % (res->width + offs.pad) == 0)
		{
			color = color_line(i, tabint, res, offs);
			if (color == NULL)
				return (print_error_min10());
			m = -1;
			while (++m < res->width)
				write(fd, color + m, 3);
			if (offs.pad > 0)
				write(fd, &zero, 4 - offs.pad);
			free(color);
		}
		i--;
	}
	return (1);
}

void	create_bmp(int *tabint, t_obj *res, int sl)
{
	int			i;
	int			fd;
	int			filesize;
	t_offset	offs;

	i = 0;
	offs.pad = (res->width * 3) % 4;
	filesize = 54 + (3 * (res->width + offs.pad) * res->high);
	fd = open("shot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666 | O_APPEND);
	offs.sl = sl;
	write_header(fd, filesize, res);
	write_image(fd, tabint, res, offs);
}
