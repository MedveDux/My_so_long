# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 10:43:47 by cyelena           #+#    #+#              #
#    Updated: 2021/10/26 18:21:49 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
		
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
HEAD = libft.h

OBJ = ${patsubst %.c,%.o,$(SRCS)}
OBJ_B = ${patsubst %.c,%.o,$(SRCS_B)}

D_FILES = ${patsubst %.c,%.d,$(SRCS) $(SRCS_B)}

CC = gcc
FLAGS = -Wall -Werror -Wextra
OPTFLAGS = -O2
RM = rm -f

TEMP_FILE = .temp_file
all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} $?
	
${OBJ} : ${HEAD} Makefile

%.o : %.c
	${CC} ${FLAGS} ${OPTFLAGS} -c $< -o $@ -MD
		
include ${wildcard ${D_FILES}}

bonus : ${TEMP_FILE}

${TEMP_FILE}: ${OBJ} ${OBJ_B} 
		ar rcs ${NAME} ${OBJ} ${OBJ_B} 
		touch ${TEMP_FILE}
		
clean:
	${RM} ${OBJ} ${D_FILES} ${OBJ_B}
	${RM} ${TEMP_FILE}

fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
