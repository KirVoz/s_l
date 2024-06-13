/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:27:00 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/13 14:30:14 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit (errno);
}

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
    char    *line;
    char    **map_line;
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
}

t_s	new_init(void)
{
    t_s game;

    game.collectabe = 0;
    game.exit = 0;
    game.hight = 0;
    game.player = 0;
    game.width = 0;
    game.x = 0;
    game.y = 0;
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
