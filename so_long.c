/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:19:05 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/11 10:47:52 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_s *game;

	game = NULL;
	if (ac != 2)
		exit (1 && write(2, "Error, few arguments\n", 21));
	game = init_map(av, game);
	
}