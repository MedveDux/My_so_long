/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:15:02 by cyelena           #+#    #+#             */
/*   Updated: 2021/10/26 19:06:26 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_index(int *i, int *sign);
static int	ft_body(const char *nptr, int i, int sign);

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;

	ft_index(&i, &sign);
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '-' \
			|| nptr[i] == '+' || nptr[i] == '\n' || nptr[i] == '\r'\
			|| nptr[i] == '\v' || nptr[i] == '\f')
	{
		if (nptr[i] == '-')
		{
			sign *= -1;
			if (nptr[i + 1] < 48 || nptr[i + 1] > 57)
				return (0);
		}	
		if (nptr[i] == '+')
		{
			if (nptr[i + 1] < 48 || nptr[i + 1] > 57)
				return (0);
		}
		i++;
	}
	return (ft_body(nptr, i, sign));
}

static int	ft_body(const char *nptr, int i, int sign)
{
	long int	sum;

	sum = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
		if (sum < 0)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
	}
	return (sum * sign);
}

static void	ft_index(int *i, int *sign)
{
	*i = 0;
	*sign = 1;
}
