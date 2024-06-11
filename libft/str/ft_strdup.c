/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:39:03 by kvoznese          #+#    #+#             */
/*   Updated: 2024/04/24 17:40:40 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	int		c;
	char	*p;

	c = ft_strlen(str);
	p = (char *)malloc(sizeof(char) * (c + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, str, c + 1);
	return (p);
}
