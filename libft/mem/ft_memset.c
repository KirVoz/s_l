/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:24:09 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:04 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	void	*str;

	str = buf;
	while (n--)
		*(unsigned char *)buf++ = (unsigned char)c;
	return (str);
}
