/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:41:57 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 18:18:44 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ch_enemy(t_s *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'e')
			{
				game->enemy++;
				game->y_e = i;
				game->x_e = j;
			}
			j++;
		}
		i++;
	}
	if (game->enemy > 1)
		exit_error(ENEMY_ERROR);
}

bool	is_wall_enemy(t_s *game, int direction)
{
	if ((direction == LEFT && (game->map[game->y_e][game->x_e - 1] != '1')
			&& (game->map[game->y_e][game->x_e - 1] != 'C')
			&& (game->map[game->y_e][game->x_e - 1] != 'E'))
		|| (direction == RIGHT && (game->map[game->y_e][game->x_e + 1] != '1')
			&& (game->map[game->y_e][game->x_e + 1] != 'C')
			&& (game->map[game->y_e][game->x_e + 1] != 'E'))
		|| (direction == DOWN && (game->map[game->y_e + 1][game->x_e] != '1')
			&& (game->map[game->y_e + 1][game->x_e] != 'C')
			&& (game->map[game->y_e + 1][game->x_e] != 'E')) || (direction == UP
			&& (game->map[game->y_e - 1][game->x_e] != '1')
			&& (game->map[game->y_e - 1][game->x_e] != 'C')
			&& (game->map[game->y_e - 1][game->x_e] != 'E')))
		return (false);
	return (true);
}

void	put_image_enemy(t_s *game, void **image, int direction)
{
	if (direction == 0)
		mlx_put_image_to_window(game->point.mlx, game->point.window, image,
			game->x_e * SIZE, game->y_e * SIZE);
	else if (direction == LEFT)
		mlx_put_image_to_window(game->point.mlx, game->point.window, image,
			(game->x_e + 1) * SIZE, game->y_e * SIZE);
	else if (direction == RIGHT)
		mlx_put_image_to_window(game->point.mlx, game->point.window, image,
			(game->x_e - 1) * SIZE, game->y_e * SIZE);
	else if (direction == DOWN)
		mlx_put_image_to_window(game->point.mlx, game->point.window, image,
			game->x_e * SIZE, (game->y_e - 1) * SIZE);
	else if (direction == UP)
		mlx_put_image_to_window(game->point.mlx, game->point.window, image,
			game->x_e * SIZE, (game->y_e + 1) * SIZE);
}

void	move_enemy(t_s *game, void **player, int direction)
{
	if (direction == 0)
	{
		put_image_enemy(game, game->point.ground, direction);
		put_image_enemy(game, player, 0);
		return ;
	}
	if (!is_wall_enemy(game, direction))
	{
		change_enemy_location_on_map(game, direction, TRUE);
		put_image_enemy(game, game->point.ground, direction);
		put_image_enemy(game, player, 0);
	}
}

int	enemy(t_s *game)
{
	int	random_move;
	int	speed;
	int	go;

	speed = 5555;
	game->loop++;
	go = game->loop % speed;
	random_move = (rand() % 5);
	if (game->map[game->y][game->x] == game->map[game->y_e][game->x_e])
		is_win(game, game->point.finish_move, game->point.play, LEFT);
	if (go == 0)
	{
		if (random_move == 4)
			move_enemy(game, game->point.enemy_left, LEFT);
		else if (random_move == 3)
			move_enemy(game, game->point.enemy_up, UP);
		else if (random_move == 2)
			move_enemy(game, game->point.enemy_right, RIGHT);
		else if (random_move == 1)
			move_enemy(game, game->point.enemy_down, DOWN);
		else
			move_enemy(game, game->point.enemy_still, 0);
	}
	return (0);
}
