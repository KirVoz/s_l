/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:21:13 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/13 14:34:32 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <errno.h>

typedef struct s_struct
{
	int	x;
	int y;
	int	hight;
	int	width;
	int	player;
	int	collectabe;
	int	exit;
}			t_s;

///////////init.c////////
void	exit_error(char *error);
void	free_map(char **map);
void	check_map(t_s *game, int fd);
t_s		new_init(void);
t_s		*init(char **av, t_s *game);
///////////parser.c//////
void	ch_col_ex_p(char **map, t_s *game);
void	ch_h_w(char **map, t_s *game);
void	ch_faktors(char **map, t_s *game);
void	check_line(char **line);
void	check_walls(char **map);
///////////flood_fill.c//
char	**create_map_copy(t_s *game, char **map);
void	flood(char **map, int y, int x, t_s *game);
void	flood_fill(t_s *game, char **map);



# define ARG_ERROR "Incorect ammount of arguments.\n"
# define FD_ERROR "FD Error.\n"
# define COLL_ERROR "Can't reach all collectales.\n"
# define EX_ERROR "Can't reach Exit.\n"
# define WALL_ERROR "No border walls.\n"
# define SIMB_ERROR "Forbiden simbols on map.\n"
# define REC_ERROR "Not rectanlular map.\n"
# define LETTER_ERROR "Incorect ammount of letters (P,C,E).\n"

#endif