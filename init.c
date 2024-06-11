/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:27:00 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/11 12:47:08 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_s	init_game(void)

{
	t_s game;
	
	game.hight = 0;
	game.width = 0;
	game.player = 0;
	game.collectabe = 0;
	game.exit = 0;
	return (game);
}

char	**check_map(int fd, t_s *game)
{
	*game = init_game();
	//?
}

char	**init_map(char **av, t_s *game)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit (1 && write(2, "Error, cant open\n", 17));
	if (ft_strnstr(av[1], ".ber", 4))
		exit (1 && write(2, "Error, not .ber file\n", 21));
	return (check_map(fd, game));
}

