/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:01:14 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 16:01:16 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_ind(int i, int j, t_obj **lst)
{
	return ((j * ((*lst)->mlx->sl) / sizeof(int)) + i);
}

void	fill_wdw(t_obj **lst, t_vecs up_r, t_vector topcorner, t_obj *res)
{
	int			i;
	int			j;
	t_vector	cachepx;
	t_vector	cachepx2;
	t_vector	px2;

	i = 0;
	while (i < res->width)
	{
		j = 0;
		px2.x = i - (res->width / 2);
		cachepx = addvector(topcorner, multvector(up_r.v2, i));
		while (j < res->high)
		{
			px2.y = (res->high - j) - (res->high / 2);
			cachepx2 = subvector(cachepx, multvector(up_r.v1, j));
			(*lst)->mlx->addr[get_ind(i, j, lst)] = does_it_hit(cachepx2, lst);
			j++;
		}
		i++;
	}
}

void	compute_wdw(t_mlx *mlx, t_obj **lst, t_obj *res, char *arg2)
{
	t_vector	px;
	double		rad;
	t_obj		*cam;
	t_vecs		up_r;

	cam = lookfor(lst, "c");
	cam->orient = get_normalized(cam->orient);
	rad = (cam->fov * M_PI) / 180;
	up_r.v1.x = 0;
	up_r.v1.y = 1;
	up_r.v1.z = 0;
	up_r.v2 = is_flat(up_r.v1, cam->orient, 0);
	up_r.v1 = get_normalized(cross_prod(cam->orient, up_r.v2));
	px = multvector(cam->orient, (res->width / (2 * tan(rad / 2))));
	px = addvector(px, multvector(up_r.v1, res->high / 2));
	px = addvector(px, multvector(up_r.v2, -res->width / 2));
	fill_wdw(lst, up_r, px, res);
	if (arg2 && ft_strncmp(arg2, "-save", 5) == 0)
	{
		create_bmp((int *)mlx->addr, res, mlx->sl);
		exit(0);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_obj	*list;
	t_obj	*res;
	t_obj	*cam;
	int		code;

	list = NULL;
	code = create_list(argv[1], &list);
	if (code != 1)
		return (0);
	mlx.ptr = mlx_init();
	cap_resolution(&list, &mlx);
	res = lookfor(&list, "R");
	mlx.wdw = mlx_new_window(mlx.ptr, res->width, res->high, "MiniRT");
	mlx.cons = mlx_new_window(mlx.ptr, 300, 150, "Console");
	mlx.img = mlx_new_image(mlx.ptr, res->width, res->high);
	mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.end);
	init_list(list, &mlx);
	compute_wdw(&mlx, &list, res, argv[2]);
	manage_console(&list);
	hook_and_loop_mlx(list);
}
