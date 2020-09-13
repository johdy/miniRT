# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdyer <jdyer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 20:58:22 by jdyer             #+#    #+#              #
#    Updated: 2020/09/10 20:59:00 by jdyer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/color/define_color.c 		\
	srcs/color/lights.c 		\
	srcs/color/shadows.c 		\
	srcs/create_bmp/create_bmp.c 		\
	srcs/deal_keys/check_param.c 		\
	srcs/deal_keys/deal_key.c 			\
	srcs/deal_keys/deal_change.c 			\
	srcs/deal_keys/deal_change_utils.c 			\
	srcs/deal_keys/manage_console.c 		\
	srcs/deal_keys/manage_console2.c 		\
	srcs/error_check/error_utils1.c 		\
	srcs/error_check/error_utils2.c 		\
	srcs/error_check/is_geom_clean.c		\
	srcs/error_check/is_line_clean.c		\
	srcs/error_check/print_error_message1.c		\
	srcs/error_check/print_error_message2.c		\
	srcs/error_check/print_error_message3.c		\
	srcs/hit/does_it_hit.c 		\
	srcs/hit/hit.c 		\
	srcs/hit/is_inside.c 		\
	srcs/read_list/create_list.c 		\
	srcs/read_list/def_geom.c		\
	srcs/read_list/def_obj.c		\
	srcs/utils/get_next_line.c 		\
	srcs/utils/get_next_line_utils.c 		\
	srcs/utils/split.c 			\
	srcs/utils/utils.c 		\
	srcs/utils/ft_atof.c 		\
	srcs/utils/manip_lst.c 		\
	srcs/utils/vector_manip1.c 		\
	srcs/utils/vector_manip2.c 		\
	srcs/utils/minmax.c 			\
	srcs/minirt.c

OBJS = $(SRCS:.c=.o)

INCLUDES = inc/ 

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBMLXDIR	= libmlxlinux
	MLX_INCLUDE = -lm -lXext -lX11
	ENV			= -D LINUX
	LIBMLX = libmlx.a
	CPLIB =

else
	LIBMLXDIR	= libmlx
	MLX_INCLUDE = -framework OpenGL -framework AppKit
	ENV			=
	LIBMLX = libmlx.dylib
	CPLIB = cp $(LIBMLXDIR)/$(LIBMLX) .

endif
LIBMLXLINK = -L $(LIBMLXDIR) -lmlx

all: cplibmlx makelibft $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBFT) $(LIBMLXLINK) $(MLX_INCLUDE) $(ENV)

cplibmlx :
	$(CPLIB)

makelibft :
	make -C $(LIBFTDIR)

%.o: %.c $(INCLUDES)
	$(CC) -c -I$(INCLUDES) -I$(LIBFTDIR) -I$(LIBMLXDIR) -o $@ $<


clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)

fclean:	clean
	rm -rf $(NAME)
	rm -rf libmlx.dylib
	rm -rf shot.bmp
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: 		all fclean clean re
