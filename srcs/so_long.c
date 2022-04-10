/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/10 20:50:10 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

size_t	len_with_sl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n' && s)
		i++;
	return (i);
}

char	*ft_strjoin_with_sl(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!s2)
		return (0);
	s = malloc((len_with_sl(s1) + len_with_sl(s2) + 1) * sizeof(const char));
	if (!s)
		return (0);
	while (s1 && s1[i] != '\0' && s1[i] != '\n')
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[k] != '\0' && s2[k] != '\n')
	{
		s[i] = s2[k];
		i++;
		k++;
	}
	s[i] = '\0';
	return (s);
}

void	error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == WALL_ERROR)
		ft_putstr_fd("wall error", 2);
	else if (error == PLAYER_ERROR)
		ft_putstr_fd("player error", 2);
	else if (error == ALPHABET_ERROR)
		ft_putstr_fd("alphabet error", 2);
	else if (error == RECTANGEL_ERROR)
		ft_putstr_fd("rectangl error", 2);
	else if (error == EXIT_ERROR)
		ft_putstr_fd("no exit error", 2);
	else if (error == COIN_ERROR)
		ft_putstr_fd("no collectible item error", 2);
	else if (error == FILE_ERROR)
		ft_putstr_fd("file error", 2);
	else if (error == EXTENTION_ERROR)
		ft_putstr_fd("your filename is incorrect", 2);
	else
		ft_putstr_fd("wall error", 2);
	exit(EXIT_FAILURE);
}

int	fd_map(char *path)
{
	int	fd;

	if (ft_strncmp((path + (len_with_sl(path) - 4)), ".ber", 5) != 0)
		error(EXTENTION_ERROR);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(FILE_ERROR);
	return (fd);
}

void	initialization(t_map *m, char *line)
{
	ft_memset(m, 0, sizeof(m));
	m->width = len_with_sl(line);
}

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

void	check_error(int	error_code, char *line, int wall)
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
	if (m->flags.player != 1 || m->flags.coin < 0
		|| m->flags.exit == 0)
		free(m->map);
	if (m->flags.player != 1)
		error(PLAYER_ERROR);
	else if (m->flags.coin < 0)
		error(COIN_ERROR);
	else if (m->flags.exit == 0)
		error (EXIT_ERROR);

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
	m->height = i;
	check_error_after(m);
}

int	main(int argc, char **argv)
{
	t_data	m;
	char	*tmp;
	int	i = 0;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments!", 2);
		return (EXIT_FAILURE);
	}
	parsing(argv[1], &m.map);
	i = m.map.height;
	tmp = m.map.map;
	while (i--)
	{
		write(1, tmp, m.map.width);
		write(1, "\n", 1);
		tmp += m.map.width;
	}
	
	// mlx_loop(m.mlx);
}
