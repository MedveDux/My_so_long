/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:23:55 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/28 16:58:16 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_img(t_data *m)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < OBJ && m->img[i])
		i++;
	if (i != OBJ)
	{
		mlx_destroy_window(m->mlx, m->win);
		while (j < OBJ)
		{
			if (m->img[j] != NULL)
				mlx_destroy_image(m->mlx, m->img[j]);
			j++;
		}
		free(m->mlx);
		free(m->map.map);
		error(MLX_ERROR);
	}
}

void	render(t_data *m, int i)
{
	int	j;

	while (++i < m->map.height)
	{
		j = -1;
		while (++j < m->map.width)
		{
			mlx_put_image_to_window(m->mlx, m->win, m->img[WATER], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->img[WALL1], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->img[COIN], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->img[EXIT], \
				j * SCALE, i * SCALE);
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img[PLAYER], \
				m->player.x * SCALE, m->player.y * SCALE);
	mlx_put_image_to_window(m->mlx, m->win, m->img[BAD], \
				m->enemy.x * SCALE, m->enemy.y * SCALE);
}

void	image(t_data *m)
{
	int	x;
	int	y;

	m->img[WALL1] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/seaweed_1.xpm", &x, &y);
	m->img[WALL2] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/seaweed_2.xpm", &x, &y);
	m->img[WALL3] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/seaweed_3.xpm", &x, &y);
	m->img[WATER] = mlx_xpm_file_to_image(m->mlx,
			"./texture/water.xpm", &x, &y);
	m->img[BAD] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/fish_bad.xpm", &x, &y);
	m->img[COIN] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/worm.xpm", &x, &y);
	m->img[PLAYER] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/player.xpm", &x, &y);
	m->img[EXIT] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/bubble.xpm", &x, &y);
	check_img(m);
}

void	ft_image(int move, t_data *m, int x, int y)
{
	if (move == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->img[WATER],
			m->player.x * SCALE, m->player.y * SCALE);
		mlx_put_image_to_window(m->mlx, m->win, m->img[WATER],
			x * SCALE, y * SCALE);
		mlx_put_image_to_window(m->mlx, m->win, m->img[PLAYER],
			x * SCALE, y * SCALE);
	}
	else if (move == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->img[WATER],
			m->player.x * SCALE, m->player.y * SCALE);
		mlx_put_image_to_window(m->mlx, m->win, m->img[WATER],
			x * SCALE, y * SCALE);
		mlx_put_image_to_window(m->mlx, m->win, m->img[PLAYER],
			x * SCALE, y * SCALE);
		m->map.map[y * m->map.width + x] = '0';
		m->map.flags.coin--;
	}
}

char	*ft_part_parsing(char *argv, t_data *m, int *fd, char *line)
{
	*fd = fd_map(argv);
	line = get_next_line(*fd);
	if (line == NULL)
	{
		free (line);
		error(EXTENTION_ERROR);
	}
	return (line);
}
