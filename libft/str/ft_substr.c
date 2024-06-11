/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:38:15 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:41:29 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l < start)
		len = 0;
	if (l + start < len)
		len = l + start;
	m = malloc(sizeof(char) * (len + 1));
	if (!m)
		return (0);
	ft_strlcpy(m, &s[start], len + 1);
	return (m);
}
