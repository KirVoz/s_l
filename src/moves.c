/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:04:39 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/17 20:05:35 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_moves(t_s *game)
{
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	move(t_s *game, void **player, int direction)
{
	if (!is_wall(game, direction))
	{
		change_location_on_map(game, direction, TRUE);
		check_if_collectible(game);
		if (!is_exit(game, direction))
		{
			put_image_direction(game, game->point.ground, direction);
			put_image_direction(game, player, 0);
			put_moves(game);
		}
	}
}

int	key_managment(int keycode, t_s *game)
{
	if (keycode == UP || keycode == 13)
		move(game, game->point.up, UP);
	else if (keycode == RIGHT || keycode == 2)
		move(game, game->point.right, RIGHT);
	else if (keycode == LEFT || keycode == 0)
		move(game, game->point.left, LEFT);
	else if (keycode == DOWN || keycode == 1)
		move(game, game->point.play, DOWN);
	if (keycode == ESC)
		end_game(game);
	return (0);
}

