/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:24:24 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/08 00:30:06 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_s	*ft_lstnew(int content)
{
	t_s	*tmp;

	tmp = (t_s *)malloc(sizeof(t_s));
	if (!tmp)
		return (NULL);
	tmp->num = content;
	tmp->next = NULL;
	return (tmp);
}
