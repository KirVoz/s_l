/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:27:25 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/13 17:29:53 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map_copy(t_s *game, char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * game->hight);
	while (game->hight > i)
	{
		map_copy[i] = malloc(sizeof(char) * (game->width + 1));
		ft_strncpy(map_copy[i], map[i], game->width + 1);
		i++;
	}
	return (map_copy);
}

void	flood(char **map, int y, int x, t_s *game)
{
	while (map[y][x] != '1' && map[y][x] != 'X')
	{
		if (map[y][x] == 'C')
			game->collectabe--;
		if (map[y][x] == 'E')
			game->exit--;
		map[y][x] = 'X';
		flood(map, y + 1, x, game);
		flood(map, y - 1, x, game);
		flood(map, y, x + 1, game);
		flood(map, y, x - 1, game);
	}
}

void	flood_fill(t_s *game, char **map)
{
	char **map_copy;

	map_copy = create_map_copy(game, map);
	flood(map_copy, game->y, game->x, game);
	if (game->collectabe != 0)
		exit_error (COLL_ERROR);
	if (game->exit != 0)
		exit_error (EX_ERROR);
}
