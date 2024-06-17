/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:19:05 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/17 21:49:12 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit (errno);
}

void	start_game(t_s *game)
{
	game->point.mlx = mlx_init();
	game->point.window = mlx_new_window(game->point.mlx, SIZE * game->width, SIZE * game->hight, "BOO");
	init_xpms(game);
	init_map_images(game);
	mlx_hook(game->point.window, 17, 0, end_game, game);
	mlx_key_hook(game->point.window, key_managment, game);
	mlx_loop(game->point.mlx);
}

int	main(int ac, char **av)
{
    t_s		game;

    if (ac != 2)
        exit_error (ARG_ERROR);
	init(av, &game);
	//system ("leaks so_long");
	start_game(&game);
    // printf("%s\n%s\n%s\n%s\n%s\n", game.map[0], game.map[1], game.map[2], game.map[3], game.map[4]);
	// printf("%d-x, %d-y", game.x, game.y);
    return (0);
}
