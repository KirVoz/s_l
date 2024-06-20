/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:53:05 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 18:32:31 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strrncmp(const char *s1, const char *s2, int n)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2 || n < 0)
		return (0);
	while ((s1[--len1] == s2[--len2]) && (n > 0))
		n--;
	if (n == 0)
		return (1);
	return (0);
}
