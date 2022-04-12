/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:15:08 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/12 18:27:30 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_line(char *line, t_map *m)
{
	size_t	i;

	i = 0;
	if (line[i] != '1')
		return (WALL_ERROR);
	m->flags.wall = 1;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (m->flags.wall && line[i] != '1')
			m->flags.wall = 0;
		if (line[i] == 'E')
			m->flags.exit++;
		else if (line[i] == 'P')
			m->flags.player++;
		else if (line[i] == 'C')
			m->flags.coin++;
		else if (line[i] != '0' && line[i] != '1')
			return (ALPHABET_ERROR);
		i++;
	}
	if (line[i - 1] != '1')
		return (WALL_ERROR);
	if (m->width != i)
		return (RECTANGEL_ERROR);
	return (0);
}

void	check_error(int error_code, char *line, int wall)
{
	if (error_code != 0)
	{
		free (line);
		error(error_code);
	}
	if (wall == 0)
	{
		free(line);
		error(WALL_ERROR);
	}
}

void	check_error_after(t_map *m)
{
	if (m->flags.wall == 0)
	{
		free(m->map);
		error(WALL_ERROR);
	}
	if (m->flags.player != 1 || m->flags.coin < 1
		|| m->flags.exit == 0)
		free(m->map);
	if (m->flags.player != 1)
		error(PLAYER_ERROR);
	else if (m->flags.coin < 1)
		error(COIN_ERROR);
	else if (m->flags.exit == 0)
		error (EXIT_ERROR);
}
