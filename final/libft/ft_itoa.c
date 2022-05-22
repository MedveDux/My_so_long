/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:09:18 by cyelena           #+#    #+#             */
/*   Updated: 2021/10/25 19:32:19 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_minus(int num)
{
	int	len_num;

	len_num = 0;
	if (num == 0)
		len_num = 1;
	if (num < 0)
	{
		len_num++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		len_num++;
	}
	return (len_num);
}

char	*ft_itoa(int n)
{
	int		l;
	long	num;
	char	*s;

	num = (long)n;
	l = ft_minus(n);
	s = malloc(l + 1);
	if (!s)
		return (0);
	s[l] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	if (num == 0)
		s[0] = '0';
	l--;
	while (l >= 0 && num != 0)
	{
		s[l] = num % 10 + '0';
		num = num / 10;
		l--;
	}
	return (s);
}
