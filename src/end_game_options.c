/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:32:16 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 18:06:11 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

int	end_game(t_s *game)
{
	destroy_images(game);
	mlx_clear_window(game->point.mlx, game->point.window);
	mlx_destroy_window(game->point.mlx, game->point.window);
	free_map(game->map);
	ft_putstr_fd("GAME ENDED\n", 1);
	exit(errno);
	return (0);
}
