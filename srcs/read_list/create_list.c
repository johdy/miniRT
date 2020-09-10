/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:36:07 by jdyer             #+#    #+#             */
/*   Updated: 2020/08/23 15:36:09 by jdyer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_camadd(t_obj **alst, t_obj *new)
{
	t_obj *item;

	if (*alst)
		item = lookfor(alst, "c");
	while (item->nextcam)
		item = item->nextcam;
	item->nextcam = new;
}

void	add_obj(t_obj **lst, t_obj *new, int *camcount)
{
	if (ft_strncmp(new->label, "c", ft_strlen(new->label)) == 0)
	{
		(*camcount)++;
		if (*camcount > 1)
			ft_camadd(lst, new);
		else
			ft_lstadd(lst, new, 0);
	}
	else
		ft_lstadd(lst, new, 1);
}

void	create_obj(char **words, t_obj **lst, int *camcount)
{
	t_obj *new;
	t_obj *new2;

	new = def_obj(words, 0);
	if (new)
		add_obj(lst, new, camcount);
	if (new && ft_strncmp(new->label, "cy", 2) == 0)
	{
		new2 = def_obj(words, 1);
		if (new2)
			add_obj(lst, new2, camcount);
	}
}

int		read_file(t_obj **lst, char *file, int *camcount, t_majcount *ar)
{
	int		fd;
	char	*line;
	char	**words;
	int		gnl;
	int		code;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	gnl = 1;
	code = 1;
	while (gnl > 0 && code == 1)
	{
		gnl = get_next_line(fd, &line);
		if (gnl != -1 && ft_strlen(line) > 0)
		{
			words = split(line, " 	");
			code = is_line_clean(words, ar);
			if (code == 1)
				create_obj(words, lst, camcount);
		}
		free(line);
	}
	return (code);
}

int		create_list(char *file, t_obj **lst)
{
	int			camcount;
	int			code;
	t_majcount	ar;
	int			i;

	i = 0;
	ar.a = 0;
	ar.r = 0;
	camcount = 0;
	while (file[i])
		i++;
	if (ft_strncmp(file + i - 3, ".rt", 3) != 0)
		return (print_error_message(-1));
	code = read_file(lst, file, &camcount, &ar);\
	if (code == 1 && (!camcount || !ar.a || !ar.r))
		code = 101;
	if (code == 1)
	{
		bindcams(lst, lookfor(lst, "c"));
		(*lst)->currelem = *lst;
	}
	else
		print_error_message(code);
	return (code);
}
