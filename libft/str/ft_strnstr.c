/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 02:07:53 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:41:17 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	j;

	if (!haystack && !n)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n--)
	{
		j = 0;
		while (*(haystack + j) == *(needle + j) && *(needle + j) && j <= n)
		{
			if (!*(needle + j + 1))
				return ((char *) haystack);
			j++;
		}
		haystack++;
	}
	return (NULL);
}
