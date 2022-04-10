/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:26:05 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/10 20:19:36 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"

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
};

typedef struct s_flags
{
	int		wall;
	int		player;
	int		exit;
	int		coin;
}	t_flags;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_flags	flags;
	char	*map;
}	t_map;

typedef struct s_data
{
	size_t	x;
	size_t	y;
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
}	t_data;

#endif

//if (ft_strncmp(&path[ft_strlen_sl(path) - 4], ".ber", 5) != 0)//check if 4 or 5 -
//&path[ft_strlen_sl(path) - 4]
//path[ft_strlen_sl(path) - 4] == *(path + (ft_strlen_sl(path) - 4))
//(path + (ft_strlen_sl(path) - 4)) == &path[ft_strlen_sl(path) - 4]