# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:56:09 by cyelena           #+#    #+#              #
#    Updated: 2022/04/10 20:45:09 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	srcs/so_long.c get_next_line/get_next_line.c
OBJS		=	$(SRCS:.c=.o)

HEAD		=	headers/so_long.h headers/get_next_line.h
HEAD_LIBFT	=	libft/libft.h

CC			=	gcc
RM			=	rm -rf
FLAGS		=	-Wall -Werror -Wextra
FLAGS_MXL	=	-lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJS)
				make -C ./minilibx_opengl_20191021
				make -C ./libft
				$(CC) $(FLAGS) $(FLAGS_MXL) $(OBJS) libft/libft.a -o $(NAME)

%.o:	%.c Makefile $(HEAD)
					$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			make clean -C ./libft
			make clean -C ./minilibx_opengl_20191021
fclean:		clean
		make fclean -c ./libft
		$(RM) $(NAME)
re:	fclean all
		make re -C ./libft
		make re -C ../minilibx_opengl_20191021
.PHONY:		all clean fclean re		