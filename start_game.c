/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:31:38 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/13 17:37:16 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_s *game)
{
	game->point.mlx = mlx_init();
	game->point.window = mlx_new_window(game->point.mlx, (SIZE * game->hight),
			(SIZE * game->width), "Pepe's adventure");
}