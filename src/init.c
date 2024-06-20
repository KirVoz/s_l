/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:27:00 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 18:06:01 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_norm(t_s *game)
{
	check_line(game);
	check_walls(game);
	ch_faktors(game);
	flood_fill(game);
}

void	check_map(t_s *game, int fd)
{
	char	**map_line;
	char	*line;
	char	*buf;
	char	*tmp;

	line = NULL;
	buf = get_next_line(fd);
	while (buf != NULL)
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
		buf = get_next_line(fd);
	}
	map_line = ft_split(line, '\n');
	free(line);
	game->map = map_line;
	check_norm(game);
}

t_s_p	init_pointers(void)
{
	t_s_p	pointers;

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
	pointers.enemy_up = NULL;
	pointers.enemy_right = NULL;
	pointers.enemy_down = NULL;
	pointers.enemy_left = NULL;
	pointers.enemy_still = NULL;
	return (pointers);
}

t_s	new_init(void)
{
	t_s	game;

	game.loop = 0;
	game.enemy = 0;
	game.x_e = 0;
	game.y_e = 0;
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
		exit_error(FD_ERROR);
	if (!ft_strrncmp(av[1], ".ber", 4))
		exit_error(BER_ERROR);
	*game = new_init();
	check_map(game, fd);
	return (game);
}
