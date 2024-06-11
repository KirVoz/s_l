/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:36:58 by kvoznese          #+#    #+#             */
/*   Updated: 2024/05/08 00:24:43 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_s **lst, void (*del)(void *))
{
	t_s	*tmp;
	t_s	*tmp2;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = tmp2;
	}
	*lst = NULL;
}
