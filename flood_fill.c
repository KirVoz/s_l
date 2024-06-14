/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:27:25 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/14 18:33:45 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map_copy(t_s *game, char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * game->hight + 1);
	if (!map_copy)
		exit_error(MALLOC_ERROR);
	while (game->hight > i)
	{
		map_copy[i] = malloc(sizeof(char) * (game->width + 1));
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[i--]);
			free(map_copy);
		}
		ft_strncpy(map_copy[i], map[i], game->width + 1);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	flood(char **map, int y, int x, t_s *game)
{
	while (map[y][x] != '1' && map[y][x] != 'X')
	{
		if (map[y][x] == 'C')
			game->temp--;
		if (map[y][x] == 'E')
			game->exit--;
		map[y][x] = 'X';
		flood(map, y + 1, x, game);
		flood(map, y - 1, x, game);
		flood(map, y, x + 1, game);
		flood(map, y, x - 1, game);
	}
}

void	flo_fil(char **map, int y, int x, t_s *game)
{
	while (map[y][x] != '1' && map[y][x] != 'X' && map[y][x] != 'E')
	{
		if (map[y][x] == 'C')
			game->temp--;
		map[y][x] = 'X';
		flo_fil(map, y + 1, x, game);
		flo_fil(map, y - 1, x, game);
		flo_fil(map, y, x + 1, game);
		flo_fil(map, y, x - 1, game);
	}
}

bool	exit_flood(t_s *game, char **map)
{
	char **map_copy;
	
	game->temp = game->collectabe;
	map_copy = create_map_copy(game, map);
	flo_fil(map_copy, game->y, game->x, game);
	free_map(map_copy);
	if (game->temp != 0)
		return (true);
	return (false);
}

void	flood_fill(t_s *game, char **map)
{
	char **map_copy;

	game->temp = game->collectabe;
	map_copy = create_map_copy(game, map);
	flood(map_copy, game->y, game->x, game);
	free_map(map_copy);
	if (game->temp != 0)
		exit_error (COLL_ERROR);
	if (game->exit != 0)
		exit_error (EX_ERROR);
	if (exit_flood(game, map))
		exit_error (BLOCKED_ERROR);
}
