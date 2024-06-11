/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:32:09 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:39:47 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	m;

	m = count * size;
	if (size && m >= SIZE_MAX / size)
		return (NULL);
	p = malloc(m);
	if (p && size)
		ft_bzero(p, m);
	return (p);
}
