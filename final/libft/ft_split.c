/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:08:36 by cyelena           #+#    #+#             */
/*   Updated: 2021/10/25 22:01:25 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) \
		|| (s[i] != c && !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free(char **s1)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i++]);
	}
	free(s1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		start;

	start = 0;
	i = 0;
	if (!s)
		return (0);
	array = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (0);
	array[ft_words(s, c)] = NULL;
	while (i < ft_words(s, c))
	{
		while (s[start] == c)
			start++;
		array[i] = ft_substr (s, start, ft_len_c(&s[start], c));
		if (!array[i])
			return (ft_free(array));
		start += ft_len_c(&s[start], c);
		i++;
		start++;
	}
	array[i] = 0;
	return (array);
}
