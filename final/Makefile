# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:56:09 by cyelena           #+#    #+#              #
#    Updated: 2022/05/22 17:42:27 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

SRCS		=	srcs/so_long.c \
				get_next_line/get_next_line.c \
				srcs/parsing_utils.c \
				srcs/parsing.c \
				srcs/mlx_loop_hook.c \
				srcs/image.c \
				srcs/mlx_hook.c

SRCS_B		=	srcs_bonus/so_long_bonus.c \
				get_next_line_bonus/get_next_line_bonus.c \
				srcs_bonus/parsing_utils_bonus.c \
				srcs_bonus/parsing_bonus.c \
				srcs_bonus/mlx_loop_hook_bonus.c \
				srcs_bonus/image_bonus.c \
				srcs_bonus/mlx_hook_bonus.c				 
				 
SRCS_LIB	=	libft/ft_atoi.c			libft/ft_memmove.c	libft/ft_toupper.c \
				libft/ft_bzero.c		libft/ft_memset.c \
				libft/ft_calloc.c		libft/ft_putchar_fd.c \
				libft/ft_isalnum.c		libft/ft_putendl_fd.c\
				libft/ft_isalpha.c		libft/ft_putnbr_fd.c\
				libft/ft_isascii.c		libft/ft_putstr_fd.c\
				libft/ft_isdigit.c		libft/ft_split.c\
				libft/ft_isprint.c		libft/ft_strchr.c\
				libft/ft_itoa.c			libft/ft_strdup.c\
				libft/ft_lstadd_back.c	libft/ft_striteri.c\
				libft/ft_lstadd_front.c	libft/ft_strjoin.c\
				libft/ft_lstclear.c		libft/ft_strlcat.c\
				libft/ft_lstdelone.c	libft/ft_strlcpy.c\
				libft/ft_lstiter.c		libft/ft_strlen.c\
				libft/ft_lstlast.c		libft/ft_strmapi.c\
				libft/ft_lstmap.c		libft/ft_strncmp.c\
				libft/ft_lstnew.c		libft/ft_strnstr.c\
				libft/ft_lstsize.c		libft/ft_strrchr.c\
				libft/ft_memchr.c		libft/ft_strtrim.c\
				libft/ft_memcmp.c		libft/ft_substr.c\
				libft/ft_memcpy.c		libft/ft_tolower.c

MLX			=	minilibx_opengl_20191021/font.c\
				minilibx_opengl_20191021/font.xcf\
				minilibx_opengl_20191021/mlx_init_loop.m\
				minilibx_opengl_20191021/mlx_int_str_to_wordtab.c\
				minilibx_opengl_20191021/mlx_int.h\
				minilibx_opengl_20191021/mlx_mouse.m\
				minilibx_opengl_20191021/mlx_new_image.m\
				minilibx_opengl_20191021/mlx_new_window.h\
				minilibx_opengl_20191021/mlx_new_window.m\
				minilibx_opengl_20191021/mlx_opengl.h\
				minilibx_opengl_20191021/mlx_opengl.m\
				minilibx_opengl_20191021/mlx_png.c\
				minilibx_opengl_20191021/mlx_png.h\
				minilibx_opengl_20191021/mlx_rgb.c\
				minilibx_opengl_20191021/mlx_shaders.c\
				minilibx_opengl_20191021/mlx_xpm.c\
				minilibx_opengl_20191021/mlx.h
				
LIBFT 		= libft/libft.a
MLX			= minilibx_opengl_20191021/libmlx.a

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

HEAD		=	headers/so_long.h headers/get_next_line.h
HEAD_B		=	headers_bonus/so_long_bonus.h headers_bonus/get_next_line_bonus.h
HEAD_LIBFT	=	libft/libft.h

CC			=	gcc -g
RM			=	rm -rf
FLAGS		=	-Wall -Werror -Wextra
FLAGS_MXL	=	-lmlx -framework OpenGL -framework AppKit

all:		$(LIBFT) $(NAME)

bonus:		$(LIBFT) $(NAME_BONUS)

$(LIBFT):	$(HEAD_LIBFT) $(SRCS_LIB)
			make -C ./libft
$(MLX):		minilibx_opengl_20191021/mlx.h

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
				make -C ./minilibx_opengl_20191021
				$(CC) $(FLAGS) $(FLAGS_MXL) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
				$(RM) $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_B) $(LIBFT) $(MLX)
				make -C ./minilibx_opengl_20191021
				$(CC) $(FLAGS) $(FLAGS_MXL) $(OBJS_B) $(LIBFT) $(MLX) -o $(NAME_BONUS)
				$(RM) $(NAME) 

%.o:	%.c Makefile $(HEAD)
					$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBJS_B)
			make clean -C ./libft
			make clean -C ./minilibx_opengl_20191021
fclean:		clean
		make fclean -C ./libft
		$(RM) $(NAME) $(NAME_BONUS)
re:	fclean all
		make re -C ./libft
		make re -C ../minilibx_opengl_20191021
.PHONY:		all clean fclean re	bonus