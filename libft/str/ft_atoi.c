/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 04:00:50 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/02 19:05:18 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	space(int c)
{
	if ((c >= 9 && c <= 14) || (c == 32))
		return (1);
	return (0);
}

static int	digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str, int *overflow)
{
	long int		n;
	long int		check;
	int				sign;

	n = 0;
	sign = 1;
	while (*str && space(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str && digit(*str))
	{
		check = INT_MIN;
		n = n * 10 + sign * (*str - 48);
		if ((n > 2147483647) || (n < check))
			*overflow = 1;
		str++;
	}
	return (n);
}
