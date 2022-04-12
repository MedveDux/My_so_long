/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:56 by cyelena           #+#    #+#             */
/*   Updated: 2022/04/12 18:20:04 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

size_t	len_with_sl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
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
	if (s2 == NULL)
		return (NULL);
	s = malloc((len_with_sl(s1) + len_with_sl(s2) + 1) * sizeof(const char));
	if (!s)
		return (NULL);
	while (s1 && s1[i] != '\0' && s1[i] != '\n')
	{
		s[i++] = s1[k];
		k++;
	}
	k = 0;
	while (s2[k] != '\0' && s2[k] != '\n')
	{
		s[i++] = s2[k];
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
