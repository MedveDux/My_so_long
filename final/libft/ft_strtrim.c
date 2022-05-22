/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:43:55 by cyelena           #+#    #+#             */
/*   Updated: 2021/10/25 19:34:22 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	len = ft_strlen(s1 + i);
	while (ft_strchr(set, s1[len + i]) && len)
		len--;
	s = ft_substr(s1, i, len + 1);
	return (s);
}
