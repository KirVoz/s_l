/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:58:54 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:49 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	l;

	if (!dest && !dstsize)
		return (0);
	l = ft_strlen(dest);
	if (dstsize < l)
		return (dstsize + ft_strlen(src));
	return (l + ft_strlcpy(dest + l, src, dstsize - l));
}
