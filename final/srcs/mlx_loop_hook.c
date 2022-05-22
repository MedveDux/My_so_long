/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:20:19 by cyelena           #+#    #+#             */
/*   Updated: 2022/05/22 19:02:47 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/so_long_bonus.h"

void	ft_move_bad_fish(t_data *m, int x, int y)
{
	char	move;

	move = m->map.map[y * m->map.width + x];
	if (m->player.x == x && m->player.y == y)
	{
		ft_putstr_fd("You died! ", 1);
		ft_putnbr_fd(m->steps, 1);
		ft_putstr_fd(" steps!\n", 1);
		ft_exit(m);
	}
	if (move == '0')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->img[WATER],
			m->enemy.x * SCALE, m->enemy.y * SCALE);
		mlx_put_image_to_window(m->mlx, m->win, m->img[WATER],
			x * SCALE, y * SCALE);
		mlx_put_image_to_window(m->mlx, m->win, m->img[BAD],
			x * SCALE, y * SCALE);
		m->enemy.y = y;
		m->enemy.x = x;
	}
}

void	bad_fish(t_data *m)
{
	static int	i;

	i = rand() % 4;
	if (i == 0)
		ft_move_bad_fish(m, m->enemy.x + 1, m->enemy.y);
	else if (i == 1)
		ft_move_bad_fish(m, m->enemy.x - 1, m->enemy.y);
	else if (i == 2)
		ft_move_bad_fish(m, m->enemy.x, m->enemy.y - 1);
	else
		ft_move_bad_fish(m, m->enemy.x, m->enemy.y + 1);
}

int	seaweed(t_data *m)
{
	static long	count = 0;
	static int	i = 0;

	if (count % (DELAY) == 0)
	{
		seaweed_util(m, i % 3);
		bad_fish(m);
		if (i % 3 == 0)
			i = 0;
		i++;
		count = 0;
	}
	count++;
	return (0);
}

void	ft_move(t_data *m, int x, int y)
{
	char	move;

	move = m->map.map[y * m->map.width + x];
	if (move == 'E' && m->map.flags.coin == 0)
		win_game(m);
	if (move == '1' || (move == 'E' && m->map.flags.coin > 0))
		return ;
	if (m->enemy.x == x && m->enemy.y == y)
	{
		ft_putstr_fd("You died! ", 1);
		ft_putnbr_fd(m->steps, 1);
		ft_putstr_fd(" steps!\n", 1);
		ft_exit(m);
	}
	ft_image(move, m, x, y);
	m->player.y = y;
	m->player.x = x;
	m->steps++;
	ft_putstr_fd("Move: ", 1);
	ft_putnbr_fd(m->steps, 1);
	ft_putstr_fd("\n", 1);
}

void	seaweed_util(t_data *m, enum e_objects seaweed)
{
	int		i;
	int		j;
	char	*itoa;

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
				mlx_string_put(m->mlx, m->win, 10, 15, 0x880000, "Moves: ");
				itoa = ft_itoa(m->steps);
				mlx_string_put(m->mlx, m->win, 70, 15, 0x880000, itoa);
				free(itoa);
			}
			j++;
		}
		i++;
	}
}
