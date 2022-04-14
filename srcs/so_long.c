/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/14 21:14:03 by cyelena          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	m;
	char	*tmp;//
	int	i = 0;//
	void *chr;//
	int x, y;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments!", 2);
		return (EXIT_FAILURE);
	}
	parsing(argv[1], &m.map);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, m.map.width * SCALE, m.map.height * SCALE, "so long");
	if (m.mlx == NULL || m.win == NULL)
	{
		free(m.win);
		error(MLX_ERROR);
	}
	chr = mlx_xpm_file_to_image(m.mlx, "/Users/cyelena/Desktop/My_so_long/texture/water.xpm", &x, &y);
	mlx_put_image_to_window(m.mlx, m.win, chr, 0, 0);
	chr = mlx_xpm_file_to_image(m.mlx, "/Users/cyelena/Desktop/My_so_long/texture/fish_player.xpm", &x, &y);
	mlx_put_image_to_window(m.mlx, m.win, chr, 0, 0);
	i = m.map.height;//
	tmp = m.map.map;//
	while (i--)//
	{//
		write(1, tmp, m.map.width);//
		write(1, "\n", 1);//
		tmp += m.map.width;//
	}//
	mlx_loop(m.mlx);
}
