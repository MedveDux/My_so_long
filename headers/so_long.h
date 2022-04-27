/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:26:05 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/19 18:56:15 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <time.h>
# include "../minilibx_opengl_20191021/mlx.h"

# ifndef SCALE
#  define SCALE 100
# endif

# ifndef OBJ
#  define OBJ 8
# endif

# ifndef DELAY
#  define DELAY 4000
# endif

enum e_keys
{
	RIGHT_KEY = 124,
	LEFT_KEY = 123,
	UP_KEY = 126,
	DOWN_KEY = 125,
	D_KEY = 2,
	A_KEY = 0,
	W_KEY = 13,
	S_KEY = 1,
	ESC = 53,
};

enum e_errors
{
	WALL_ERROR = 1,
	PLAYER_ERROR = 2,
	ALPHABET_ERROR = 3,
	RECTANGEL_ERROR = 4,
	EXIT_ERROR = 5,
	COIN_ERROR = 6,
	FILE_ERROR = 7,
	EXTENTION_ERROR = 8,
	MLX_ERROR = 9,
	ENEMY_ERROR = 10,
};

typedef struct s_flags
{
	int		wall;
	int		player;
	int		exit;
	int		enemy;
	int		coin;
}	t_flags;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_flags	flags;
	char	*map;
}	t_map;

typedef struct s_player
{
	size_t	x;
	size_t	y;
}	t_player;

typedef struct s_enemy
{
	size_t	x;
	size_t	y;
	size_t	prev_x;
	size_t	prev_y;
}	t_enemy;

typedef struct s_data
{
	int			steps;
	void		*mlx;
	void		*win;
	void		*img[OBJ];
	t_map		map;
	t_player	player;
	t_enemy		enemy;
}	t_data;

enum e_objects
{
	WALL1,
	WALL2,
	WALL3,
	WATER,
	BAD,
	COIN,
	PLAYER,
	EXIT,
};

//so_long

//parsing_utils
size_t	len_with_sl(const char *s);
char	*ft_strjoin_with_sl(char const *s1, char const *s2);
void	error(int error);
int		fd_map(char *path);
//parsing
int		check_char(t_data *m, char *line, int y, int count);
int		check_line(char *line, t_data *m, int y);
void	check_error(int error_code, char *line, int wall);
void	check_error_after(t_map *m);
#endif