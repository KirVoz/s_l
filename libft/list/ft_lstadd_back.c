/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:55:07 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/20 12:54:39 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_s **lst, t_s *new)
{
	t_s	*l;

	l = ft_lstlast(*lst);
	if (!l)
		*lst = new;
	else
		l->next = new;
}
