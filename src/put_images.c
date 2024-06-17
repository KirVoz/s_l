/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:57:45 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/17 20:46:41 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_s *game, void **image, int x, int y)
{
	mlx_put_image_to_window
		(game->point.mlx, game->point.window, image, x * SIZE, y * SIZE);
}

void	put_image_direction(t_s *game, void **image, int direction)
{
	if (direction == 0)
		mlx_put_image_to_window
		(game->point.mlx, game->point.window, image, game->x * SIZE, game->y * SIZE);
	else if (direction == LEFT)
		mlx_put_image_to_window
		(game->point.mlx, game->point.window, image, (game->x + 1) * SIZE, game->y * SIZE);
	else if (direction == RIGHT)
		mlx_put_image_to_window
		(game->point.mlx, game->point.window, image, (game->x - 1) * SIZE, game->y * SIZE);
	else if (direction == DOWN)
		mlx_put_image_to_window
		(game->point.mlx, game->point.window, image, game->x * SIZE, (game->y - 1) * SIZE);
	else if (direction == UP)
		mlx_put_image_to_window
		(game->point.mlx, game->point.window, image, game->x * SIZE, (game->y + 1) * SIZE);
}

void	destroy_if_not_null(t_s *game, void **image)
{
	if (image)
		mlx_destroy_image(game->point.mlx, image);
}

void	destroy_images(t_s *game)
{
	destroy_if_not_null(game, game->point.ground);
	destroy_if_not_null(game, game->point.wall);
	destroy_if_not_null(game, game->point.collect);
	destroy_if_not_null(game, game->point.exit);
	destroy_if_not_null(game, game->point.play);
	destroy_if_not_null(game, game->point.up);
	destroy_if_not_null(game, game->point.left);
	destroy_if_not_null(game, game->point.right);
	destroy_if_not_null(game, game->point.finish_move);
	destroy_if_not_null(game, game->point.exit_sign);
	destroy_if_not_null(game, game->point.start_sign);
	destroy_if_not_null(game, game->point.arrow);
}
