/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:27:00 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:41:03 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*m;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	m = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = f(i, s[i]);
		++i;
	}
	m[i] = '\0';
	return (m);
}
