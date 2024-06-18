/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:25:06 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/18 18:33:03 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_location_on_map(t_s *game, int direction, int option)
{
	if ((direction == LEFT && option == TRUE)
		|| (direction == RIGHT && option == FALSE))
		game->x--;
	else if ((direction == RIGHT && option == TRUE)
		|| (direction == LEFT && option == FALSE))
		game->x++;
	else if ((direction == DOWN && option == TRUE)
		|| (direction == UP && option == FALSE))
		game->y++;
	else if ((direction == UP && option == TRUE)
		|| (direction == DOWN && option == FALSE))
		game->y--;
}

void	is_win(t_s *game, void **player, void **exit, int direction)
{
	put_image_direction(game, game->point.ground, 0);
	put_image_direction(game, exit, 0);
	put_image_direction(game, game->point.ground, direction);
	put_image_direction(game, player, direction);
	put_moves(game);
	ft_putstr_fd("\nYOU WON!!\n but what cost...\n", 1);
	end_game(game);
	//put_arrows(game, UP);
	//mlx_key_hook(game->point.window, restart_game, game);
}

bool	is_exit(t_s *game, int direction)
{
	if (game->map[game->y][game->x] == 'E')
	{
		if (game->collectabe == 0)
			is_win(game, game->point.finish_move, game->point.play, LEFT);
		change_location_on_map(game, direction, FALSE);
		return (true);
	}
	return (false);
}

bool	is_wall(t_s *game, int direction)
{
	if ((direction == LEFT && (game->map[game->y][game->x - 1] != '1'))
		|| (direction == RIGHT && (game->map[game->y][game->x + 1] != '1'))
		|| (direction == DOWN && (game->map[game->y + 1][game->x] != '1'))
		|| (direction == UP && (game->map[game->y - 1][game->x] != '1')))
		return (false);
	return (true);
}

void	check_if_collectible(t_s *game)
{
	if (game->map[game->y][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->collectabe--;
		put_image_direction(game, game->point.ground, 0);
	}
}
