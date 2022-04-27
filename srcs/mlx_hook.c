/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:26:17 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/27 16:28:07 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_init(t_data *m)
{
	m->map.map = NULL;
	m->map.width = 0;
	m->map.height = 0;
	m->map.flags.coin = 0;
	m->map.flags.enemy = 0;
	m->map.flags.exit = 0;
	m->map.flags.player = 0;
	m->map.flags.wall = 0;
}

void	init(t_data *m)
{
	m->steps = 0;
	m->player.x = 0;
	m->player.y = 0;
	m->enemy.prev_x = 0;
	m->enemy.prev_y = 0;
	m->enemy.x = 0;
	m->enemy.y = 0;
	map_init(m);
}

void	ft_exit(t_data *m)
{
	free(m->map.map);
	exit(0);
}

void    win_game(t_data *m)
{
	ft_putstr_fd("You win! Steps - ", 1);
	ft_putnbr_fd(m->steps, 1);
	ft_exit (m);
}

int ft_key(int key, t_data *m)
{
	if (key == ESC)
		ft_exit(m);
	else if (key == RIGHT_KEY || key == D_KEY)
		ft_move(m, m->player.x + 1, m->player.y);
	else if (key == LEFT_KEY || key == A_KEY)
		ft_move(m, m->player.x - 1 , m->player.y);
	else if (key == UP_KEY || key == W_KEY)
		ft_move(m, m->player.x, m->player.y - 1);
	else if (key == DOWN_KEY || key == S_KEY)
		ft_move(m, m->player.x, m->player.y + 1);
	return (0);
}
