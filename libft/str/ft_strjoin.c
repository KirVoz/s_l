/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:53:52 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:46 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*m;

	if (!s1)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	m = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!m)
		return (0);
	ft_strlcpy(m, s1, l1 + l2 + 1);
	ft_strlcat(m, s2, l1 + l2 + 1);
	return (m);
}
/*
"    he   llo    "
"he    llo"
*/
