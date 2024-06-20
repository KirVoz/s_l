/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:19:05 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 17:41:46 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit(errno);
}

void	start_game(t_s *game)
{
	game->point.mlx = mlx_init();
	game->point.window = mlx_new_window(game->point.mlx, SIZE * game->width,
			(SIZE * game->hight) + (SIZE / 2), "BOO");
	init_xpms(game);
	init_map_images(game);
	mlx_string_put(game->point.mlx, game->point.window, 8, (game->hight * SIZE)
		+ (SIZE / 2) - 4, 16071997, "JUST DO IT! BUT FASTER!:");
	mlx_hook(game->point.window, 17, 0, end_game, game);
	if (game->enemy != 0)
		mlx_loop_hook(game->point.mlx, enemy, game);
	mlx_key_hook(game->point.window, key_managment, game);
	mlx_loop(game->point.mlx);
}

int	main(int ac, char **av)
{
	t_s	game;

	if (ac != 2)
		exit_error(ARG_ERROR);
	init(av, &game);
	start_game(&game);
	return (0);
}
