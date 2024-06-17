/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:57:20 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/17 21:53:05 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	**xpm_image(t_s *game, char *path)
{
	int		size;
	int		fd;
	void	**image;

	size = SIZE;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		destroy_images(game);
		mlx_clear_window(game->point.mlx, game->point.window);
		mlx_destroy_window(game->point.mlx, game->point.window);
		free_map(game->map);
		exit_error(IMAGE_ERROR);
	}
	close(fd);
	image = mlx_xpm_file_to_image(game->point.mlx, path, &size, &size);
	return (image);
}

void	init_xpms(t_s *game)
{
	game->point.ground = xpm_image(game, "./assets/ground.xpm");
	game->point.wall = xpm_image(game, "./assets/wall.xpm");
	game->point.collect = xpm_image(game, "./assets/collectable.xpm");
	game->point.exit = xpm_image(game, "./assets/exit.xpm");
	game->point.play = xpm_image(game, "./assets/down.xpm");
	game->point.up = xpm_image(game, "./assets/up.xpm");
	game->point.left = xpm_image(game, "./assets/character_left.xpm");
	game->point.right = xpm_image(game, "./assets/character_right.xpm");
	game->point.finish_move = xpm_image(game, "./assets/finish_move.xpm");
	game->point.exit_sign = xpm_image(game, "./assets/exit_sign.xpm");
	game->point.start_sign = xpm_image(game, "./assets/start_sign.xpm");
	game->point.arrow = xpm_image(game, "./assets/arrow.xpm");
}

void	init_map_images(t_s *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->hight > x)
	{
		y = 0;
		while (y < game->width)
		{	
			put_image(game, game->point.ground, y, x);
			if (game->map[x][y] == 'P')
				put_image(game, game->point.play, y, x);
			else if (game->map[x][y] == '1')
				put_image(game, game->point.wall, y, x);
			else if (game->map[x][y] == 'C')
				put_image(game, game->point.collect, y, x);
			else if (game->map[x][y] == 'E')
				put_image(game, game->point.exit, y, x);
			y++;
		}
		x++;
	}
}
