/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:15:08 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/28 17:19:53 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_char(t_data *m, char *line, int y, int count)
{
	if (*line == 'E')
		m->map.flags.exit++;
	else if (*line == 'P')
	{
		*line = '0';
		m->map.flags.player++;
		m->player.x = count;
		m->player.y = y;
	}
	else if (*line == 'C')
		m->map.flags.coin++;
	else if (*line == 'N')
	{
		*line = '0';
		m->map.flags.enemy++;
		m->enemy.x = count;
		m->enemy.y = y;
	}
	else if (*line != '0' && *line != '1')
		return (ALPHABET_ERROR);
	return (0);
}

int	check_line(char *line, t_data *m, int y)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (WALL_ERROR);
	m->map.flags.wall = 1;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (m->map.flags.wall && line[i] != '1')
			m->map.flags.wall = 0;
		if (check_char(m, &line[i], y, i) == ALPHABET_ERROR)
			return (ALPHABET_ERROR);
		i++;
	}
	if (line[i - 1] != '1')
		return (WALL_ERROR);
	if (m->map.width != i)
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

void	parsing(char *argv, t_data *m)
{
	int		fd;
	char	*line;
	int		error_code;
	int		i;
	char	*tmp;

	line = NULL;
	line = ft_part_parsing(argv, m, &fd, line);
	error_code = check_line(line, m, 0);
	check_error(error_code, line, m->map.flags.wall);
	i = 0;
	while (line)
	{
		tmp = m->map.map;
		m->map.map = ft_strjoin_with_sl(tmp, line);
		free(tmp);
		free(line);
		if (m->map.map == NULL)
			error (42);
		line = get_next_line(fd);
		for_parsing(line, error_code, m, i);
		i++;
	}
	m->map.height = i;
	check_error_after(&m->map);
}
