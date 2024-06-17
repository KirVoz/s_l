/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:27:00 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/17 21:55:45 by kvoznese         ###   ########.fr       */
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
	free (map);
	map = NULL;
}

void	check_map(t_s *game, int fd)
{
    char    **map_line;
    char    *line;
	char	*buf;
	char 	*tmp;

	line = NULL;
	while ((buf = get_next_line(fd)) != NULL)
    {
        if (line == NULL)
            line = buf;
        else
        {
            tmp = ft_strjoin(line, buf);
            free(line);
            free(buf);
            line = tmp;
        }
    }
	map_line = ft_split(line, '\n');
    free(line);
	check_line(map_line);
	check_walls(map_line);
    ch_faktors(map_line, game);
	flood_fill(game, map_line);
	game->map = map_line;
}
t_s_p   init_pointers(void)
{
    t_s_p   pointers;

	pointers.mlx = NULL;
	pointers.window = NULL;
	pointers.arrow = NULL;
	pointers.ground = NULL;
	pointers.collect = NULL;
	pointers.wall = NULL;
	pointers.exit = NULL;
	pointers.up = NULL;
	pointers.left = NULL;
	pointers.right = NULL;
	pointers.play = NULL;
	pointers.start_sign = NULL;
	pointers.exit_sign = NULL;
	pointers.finish_move = NULL;
	return (pointers);
}

t_s	new_init(void)
{
    t_s game;

	game.arrow = 0;
	game.moves = 0;
	game.temp = 0;
	game.collectabe = 0;
    game.exit = 0;
    game.hight = 0;
    game.player = 0;
    game.width = 0;
    game.x = 0;
    game.y = 0;
	game.point = init_pointers();
    return (game);
}

t_s	*init(char **av, t_s *game)
{
	int	fd;
	
	fd = open(av[1], O_RDONLY);
    if (fd < 0)
        exit_error (FD_ERROR);
    *game = new_init();
    check_map(game, fd);
    return (game);
}
