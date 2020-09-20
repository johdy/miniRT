/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:37:36 by jdyer             #+#    #+#             */
/*   Updated: 2020/09/16 01:50:34 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "get_next_line.h"
# include <fcntl.h>
# include "keycode.h"

# define BUFFER_SIZE 4096
# define OFFSET_ROT 0.1
# define E 0.0001
# define WH 0xFFFFFF

typedef struct	s_mlx
{
	void	*ptr;
	void	*wdw;
	void	*cons;
	void	*img;
	int		*addr;
	int		bpp;
	int		sl;
	int		end;
}				t_mlx;

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

typedef struct	s_obj
{
	char			*label;
	t_vector		orig;
	t_vector		a;
	t_vector		b;
	t_vector		c;
	t_vector		orient;
	double			fov;
	double			ray;
	double			height;
	int				color;
	double			intens;
	int				width;
	int				high;
	int				camcount;
	struct s_obj	*next;
	struct s_obj	*nextcam;
	struct s_obj	*currelem;
	t_mlx			*mlx;
	int				change_off;
	int				change_rot;
	double			offset;
	char			rot[20];
	char			off[10];
}				t_obj;

typedef struct	s_hit
{
	int		color;
	double	dist;
}				t_hit;

typedef struct	s_vecs
{
	t_vector	v1;
	t_vector	v2;
	double		*intens_l;
}				t_vecs;

typedef struct	s_majcount
{
	int	a;
	int	r;
}				t_majcount;

typedef struct	s_offset
{
	int	sl;
	int	pad;
}				t_offset;

double			norm2(t_vector vec);
t_vector		subvector(t_vector vec1, t_vector vec2);
double			scalaire(t_vector vec1, t_vector vec2);
t_vector		addvector(t_vector vec1, t_vector vec2);
double			minpos(double x, double y);
double			maxpos(double x, double y);
t_vector		multvector(t_vector vec1, double m);
t_vector		get_normalized(t_vector vec);
t_vector		project(t_vector a, t_vector b);
double			*read_tuple(char *word);
t_vector		fill_vector(t_vector vec, double *tab);
int				atocol(char *col);
t_obj			*lookfor(t_obj **lst, char *label);
int				*ft_rvb(int color);
int				get_color(double *intens_l, int color, double amb);
int				define_col(t_obj **lst, t_obj *sp, t_vector hitpoint);
int				no_shadows(t_obj **lst, t_vector hitpoint, t_vector light_orig);
t_vector		hit_sphere(t_vector pt1, t_vector pt2, t_obj **lst, t_obj *sp);
double			hit_plane(t_vector orig_r, t_vector dir, t_obj *sp);
double			hit_triangle(t_vector or, t_vector di, t_obj **lst, t_obj *tr);
double			hit_square(t_vector or, t_vector di, t_obj **lst, t_obj *sq);
t_vector		hit_cylinder(t_vector or, t_vector di, t_obj **lst, t_obj *cy);
int				create_list(char *file, t_obj **lst);
double			ft_atof(const char *str);
t_obj			*def_obj(char **words);
char			**split(char *s, char *set);
void			delete_tab(char **words);
void			bindcams(t_obj **lst, t_obj *cam1);
void			ft_lstadd(t_obj **alst, t_obj *new, int front);
t_obj			*define_pl(char **words);
t_obj			*define_sp(char **words);
t_obj			*define_sq(char **words);
t_obj			*define_tr(char **words);
t_obj			*define_cy(char **words);
int				deal_key(int key, t_obj *list);
void			compute_wdw(t_mlx *mlx, t_obj **lst, t_obj *res, char *arg2);
int				does_it_hit(t_vector px, t_obj **lst);
double			cut_cylinder(t_obj *cy, t_vector t, t_vecs eye, int calc_col);
double			is_inside_square(double t, t_vecs ey, t_vector no, t_obj *sq);
double			is_inside_triangle(double t, t_vecs ey, t_vector no, t_obj *tr);
t_hit			define_point_color(t_hit r, t_obj **ls, t_obj *ob, t_vector hp);
double			*light_addition(t_obj **lst, t_obj *obj, t_vector hitpoint);
t_obj			*ft_switch_cam(t_obj **lst);
t_hit			what_would_it_hit(t_vecs ey, t_obj **lst, t_obj *elem, int col);
t_hit			empty_ret();
t_vector		cross_prod(t_vector v1, t_vector v2);
t_vector		is_flat(t_vector up, t_vector dir, int tr);
t_vector		is_straight(t_vector norm, t_vector far);
int				manage_console(t_obj **list);
void			console_tr(t_obj **list, t_obj *obj);
void			console_pl(t_obj **list, t_obj *obj);
void			console_sq(t_obj **list, t_obj *obj);
void			console_cy(t_obj **list, t_obj *obj);
void			clean_console(t_mlx *mlx);
int				is_line_clean(char **words, t_majcount *ar);
int				print_error_message(int code);
void			print_error_1(int code);
void			print_error_2(int code);
void			print_error_3(int code);
void			print_error_4(int code);
void			print_error_5(int code);
void			print_error_10(int code);
void			print_error_100(int code);
void			print_error_98(int code);
int				print_error_min10(void);
t_vector		cap_orient(t_vector orient);
double			plancher_size(t_obj *obj, double param);
int				cannot_change(int key, char *lb, int rotation);
int				check_sp(char **words);
int				check_pl(char **words);
int				check_tr(char **words);
int				check_sq(char **words);
int				check_cy(char **words);
int				check_float_pb(char *word);
int				err_clean_table(char **words, int err);
int				check_tuple(char *word);
int				check_color(char *word);
int				check_orient(char *word);
int				is_not_float(char *word);
int				is_not_int(char *word);
void			create_bmp(int *tabint, t_obj *res, int sl);
int				escapp(int key, t_obj *list);
void			cap_resolution(t_obj **list, t_mlx *mlx);
int				deal_change(int key, t_obj *list);
void			print_change_error(void);
void			print_welcome(int key, t_obj *list);
char			get_number_pressed(int key);
int				checkpoint_rot(t_obj *list);
int				clickescape(t_obj *list);
int				deal_expose_wdw(t_obj **list);
int				deal_expose_cons(t_obj **list);
void			init_list(t_obj *list, t_mlx *mlx);
void			hook_and_loop_mlx(t_obj *list);
t_vector		touch_sphere(t_vector orig_r, t_vector dir, t_obj *sp);
double			touch_square(t_vector orig_r, t_vector dir, t_obj *sq);
double			touch_plane(t_vector orig_r, t_vector dir, t_obj *pl);
double			touch_triangle(t_vector orig_r, t_vector dir, t_obj *tr);
double			touch_cylinder(t_vector orig_r, t_vector dir, t_obj *cy);
double			cut_triangle(double t, t_vecs eye, t_vector norm, t_obj *tr);
double			cut_square(double t, t_vecs eye, t_vector norm, t_obj *sq);
double			cut_cylinder_shad(t_obj *cy, t_vector t, t_vector orig_r, t_vector dir);
int				is_btw_pl(t_obj *cy, t_vector hitpoint);
#endif
