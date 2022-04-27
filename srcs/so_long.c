/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/27 16:26:53 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_data	m;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments!", 2);
		return (EXIT_FAILURE);
	}
	init(&m);
	parsing(argv[1], &m);
	m.mlx = mlx_init();
	if (m.mlx == NULL)
	{
		free (m.map.map);
		error(MLX_ERROR);
	}
	m.win = mlx_new_window(m.mlx, m.map.width * SCALE,
			m.map.height * SCALE, "so long");
	if (m.win == NULL)
	{
		free(m.mlx);
		free (m.map.map);
		error(MLX_ERROR);
	}
	image(&m);
	render(&m);
	mlx_hook(m.win, 2, 0, ft_key, &m);
	mlx_hook(m.win, 17, 0, ft_exit, &m);
	mlx_loop_hook(m.mlx, seaweed, &m);
	mlx_loop(m.mlx);
}
