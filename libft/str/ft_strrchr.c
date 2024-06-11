/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:12:36 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:41:21 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0 && str[i] != (char)ch)
		i--;
	if (i < 0)
		return (NULL);
	return ((char *)str + i);
}
