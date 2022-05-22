/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/05/22 18:45:14 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/so_long_bonus.h"

void	part_main(char **argv, t_data *m)
{
	init(m);
	parsing(argv[1], m);
	m->mlx = mlx_init();
	if (m->mlx == NULL)
	{
		free (m->map.map);
		error(MLX_ERROR);
	}
}

int	main(int argc, char **argv)
{
	t_data	m;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments!", 2);
		return (EXIT_FAILURE);
	}
	part_main(argv, &m);
	m.win = mlx_new_window(m.mlx, m.map.width * SCALE,
			m.map.height * SCALE, "so long");
	if (m.win == NULL)
	{
		free(m.mlx);
		free (m.map.map);
		error(MLX_ERROR);
	}
	image(&m);
	render(&m, -1);
	mlx_hook(m.win, 2, 0, ft_key, &m);
	mlx_hook(m.win, 17, 0, ft_exit, &m);
	mlx_loop_hook(m.mlx, seaweed, &m);
	mlx_loop(m.mlx);
}
