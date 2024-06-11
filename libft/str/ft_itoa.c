/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:46 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:29 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	dig_count(int n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (i);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i - 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	dig;
	size_t	num;

	num = n;
	dig = dig_count(n);
	if (n < 0)
	{
		num *= -1;
		dig++;
	}
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (!str)
		return (NULL);
	*(str + dig) = 0;
	while (dig--)
	{
		*(str + dig) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
