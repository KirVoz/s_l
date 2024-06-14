/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:19:05 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/14 17:12:24 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit (errno);
}

int	main(int ac, char **av)
{
    t_s game;

    if (ac != 2)
        exit_error (ARG_ERROR);
    init(av, &game);
	system ("leaks so_long");
	//start_game(&game);
    printf("%d-coll, %d-exit, %d-player, %d-hight, %d-width, %d-x, %d-y\n", game.collectabe, game.exit, game.player, game.hight, game.width, game.x, game.y);
    return (0);
}
