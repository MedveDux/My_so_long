/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:26:05 by cyelena           #+#    #+#             */
/*   Updated: 2022/05/22 16:37:54 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "get_next_line_bonus.h"
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
	int		height;
	int		width;
	t_flags	flags;
	char	*map;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_enemy
{
	int	x;
	int	y;
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
void	part_main(char **argv, t_data *m);
//parsing_utils
size_t	len_with_sl(const char *s);
char	*ft_strjoin_with_sl(char const *s1, char const *s2);
void	error(int error);
int		fd_map(char *path);
void	for_parsing(char *line, int error_code, t_data *m, int i);
//parsing
int		check_char(t_data *m, char *line, int y, int count);
int		check_line(char *line, t_data *m, int y);
void	check_error(int error_code, char *line, int wall);
void	check_error_after(t_map *m);
void	parsing(char *argv, t_data *m);
//mlx_loop_hook
void	ft_move_bad_fish(t_data *m, int x, int y);
void	bad_fish(t_data *m);
int		seaweed(t_data *m);
void	ft_move(t_data *m, int x, int y);
void	seaweed_util(t_data *m, enum e_objects seaweed);
//image
void	check_img(t_data *m);
void	render(t_data *m, int i);
void	image(t_data *m);
void	ft_image(int move, t_data *m, int x, int y);
char	*ft_part_parsing(char *argv, t_data *m, int *fd, char *line);
// mlx_hook
void	map_init(t_data *m);
void	init(t_data *m);
int		ft_exit(t_data *m);
void	win_game(t_data *m);
int		ft_key(int key, t_data *m);
#endif
