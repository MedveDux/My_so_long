/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/17 20:27:16 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	for_parsing(char *line, int error_code, t_map *m)
{
	if (line != NULL)
	{
		error_code = check_line(line, m);
		if (error_code != 0)
		{
			free(line);
			free(m->map);
			error(error_code);
		}
	}	
}

void	parsing(char *argv, t_map *m)
{
	int		fd;
	char	*line;
	int		error_code;
	int		i;
	char	*tmp;

	fd = fd_map(argv);
	line = get_next_line(fd);
	initialization(m, line);
	error_code = check_line(line, m);
	check_error(error_code, line, m->flags.wall);
	i = 0;
	while (line)
	{
		tmp = m->map;
		m->map = ft_strjoin_with_sl(tmp, line);
		free(tmp);
		free(line);
		i++;
		line = get_next_line(fd);
		for_parsing(line, error_code, m);
	}
	m->height = i;
	check_error_after(m);
}


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

void	seaweed_util(t_data *m, enum e_objects seaweed)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->map.height)
	{
		j = 0;
		while (j < m->map.width)
		{
			if ((m->map.map)[j + i * m->map.width] == '1')
			{
				mlx_put_image_to_window(m->mlx, m->win, \
				m->img[WATER], j * SCALE, i * SCALE);
				mlx_put_image_to_window(m->mlx, m->win, \
					m->img[seaweed], j * SCALE, i * SCALE);
			}
			j++;
		}
		i++;
	}
}

void	seaweed(t_data *m)
{
	static long	count = 0;
	static int	i = 0;

	if (count % (DELAY) == 0)
	{
		seaweed_util(m, i % 3);
		if (i % 3 == 0)
			i = 0;
		i++;
		count = 0;
	}
	count++;
	// if (count == DELAY - 2000)
	// 	seaweed_util(m, 0);
	// else if (count == DELAY)
	// 	seaweed_util(m, 1);
	// else if (count == DELAY + 2000)
	// {
	// 	seaweed_util(m, 2);
	// 	count = 0;
	// }
	// count++;
}


// 	if (count == (TIME * 1))
// 		seaweed_util(m, WALL1);
// 	else if (count == (TIME * 2))
// 		seaweed_util(m, WALL2);
// 	else if (count == (TIME * 3))
// 	{
// 		seaweed_util(m, WALL3);
// 		count = 0;
// 	}
// 	else
// 		count++;
// }

void	init(t_data *m)
{
	m->mlx = mlx_init();
	if (m->mlx == NULL)
	{
		free(m->map.map);
		error(MLX_ERROR);
	}
	m->win = mlx_new_window(m->mlx, m->map.width * SCALE,
			m->map.height * SCALE, "so long");
	if (m->win == NULL)
	{
		free(m->map.map);
		free(m->mlx);
		error(MLX_ERROR);
	}
}

void	render(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < m->map.height)
	{
		j = 0;
		while (j++ < m->map.width)
		{
			mlx_put_image_to_window(m->mlx, m->win, m->img[WATER], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->img[WALL1], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->img[PLAYER], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->img[COIN], \
				j * SCALE, i * SCALE);
			if ((m->map.map)[j + i * m->map.width] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->img[EXIT], \
				j * SCALE, i * SCALE);
		}
	}
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
	m->img[BED] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/fish_bad.xpm", &x, &y);
	m->img[COIN] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/worm.xpm", &x, &y);
	m->img[PLAYER] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/player.xpm", &x, &y);
	m->img[EXIT] = mlx_xpm_file_to_image(m->mlx,
			"/Users/cyelena/Desktop/My_so_long/texture/bubble.xpm", &x, &y);
	check_img(m);
}

void	ft_exit(t_data *m)
{
	free(m->map.map);
	exit(0);
}

void ft_key(t_data *m)
{
	
}

int	main(int argc, char **argv)
{
	t_data	m;
	char	*tmp;//
	int	i = 0;//
	// void *chr;//
	// int x, y;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments!", 2);
		return (EXIT_FAILURE);
	}
	parsing(argv[1], &m.map);
	init(&m);
	image(&m);
	render(&m);
	// m.mlx = mlx_init();
	// if (m.mlx == NULL)
	// 	error(MLX_ERROR);
	// m.win = mlx_new_window(m.mlx, m.map.width * SCALE, m.map.height * SCALE, "so long");
	// if (m.win == NULL)
	// {
	// 	free(m.win);// why
	// 	error(MLX_ERROR);
	// }
	// chr = mlx_xpm_file_to_image(m.mlx, "/Users/cyelena/Desktop/My_so_long/texture/seaweed_1.xpm", &x, &y);
	// mlx_put_image_to_window(m.mlx, m.win, chr, 0, 0);
	// chr = mlx_xpm_file_to_image(m.mlx, "/Users/cyelena/Desktop/My_so_long/texture/seaweed_2.xpm", &x, &y);
	// mlx_put_image_to_window(m.mlx, m.win, chr, 0, 100);
	// chr = mlx_xpm_file_to_image(m.mlx, "/Users/cyelena/Desktop/My_so_long/texture/seaweed_3.xpm", &x, &y);
	// mlx_put_image_to_window(m.mlx, m.win, chr, 0, 200);
	i = m.map.height;//
	tmp = m.map.map;//
	while (i--)//
	{//
		write(1, tmp, m.map.width);//
		write(1, "\n", 1);//
		tmp += m.map.width;//
	}//
	mlx_hook(m.win, 2, 0, ft_key, &m);
	mlx_hook(m.win, 17, 0, ft_exit, &m);
	mlx_loop_hook(m.mlx, seaweed, &m);
	mlx_loop(m.mlx);
}
