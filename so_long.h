/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:21:13 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/17 20:01:25 by kvoznese         ###   ########.fr       */
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
# include <stdbool.h>

typedef struct pointers
{
	void	*mlx;
	void 	*window;
	void	**ground;
	void	**wall;
	void	**collect;
	void	**exit;
	void	**play;
	void	**up;
	void	**left;
	void	**right;
	void	**finish_move;
	void	**exit_sign;
	void	**start_sign;
	void	**arrow;
	
}			t_s_p;

typedef struct s_struct
{
	int		arrow;
	int		moves;
	int		temp;
	int		x;
	int		y;
	int		hight;
	int		width;
	int		player;
	int		collectabe;
	int		exit;
	char 	**map;
	t_s_p	point;
}			t_s;

///////////so_long.c/////
void	exit_error(char *error);
///////////init.c////////
t_s_p   init_pointers(void);
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
///////////start_game.c//
void	init_map_images(t_s *game);
void	**xpm_image(t_s *game, char *path);
void	init_xpms(t_s *game);
void	start_game(t_s *game);
//end_game_options.c
int		end_game(t_s *game);
//put_images.c
void	put_image(t_s *game, void **image, int x, int y);
void	put_image_direction(t_s *game, void **image, int direction);
void	destroy_if_not_null(t_s *game, void **image);
void	destroy_images(t_s *game);
//moves.c
void	put_moves(t_s *game);
void	move(t_s *game, void **player, int direction);
int key_managment(int keycode, t_s *game);
int NewFunction(int keycode, t_s *game);
// move_helper.c
void change_location_on_map(t_s *game, int direction, int option);
void is_win(t_s *game, void **player, void **exit, int direction);
bool	is_exit(t_s *game, int direction);
bool	is_wall(t_s *game, int direction);
void	check_if_collectible(t_s *game);


# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# define ENTER 36

# define SIZE 32
# define ESC 53

// # define ENTER 15
// # define UP 87
// # define DOWN 83
// # define LEFT 65
// # define RIGHT 68

# define TRUE 0
# define FALSE 1

# define ARG_ERROR "Incorect ammount of arguments.\n"
# define FD_ERROR "FD Error.\n"
# define COLL_ERROR "Can't reach all collectales.\n"
# define EX_ERROR "Can't reach Exit.\n"
# define WALL_ERROR "No border walls.\n"
# define SIMB_ERROR "Forbiden simbols on map.\n"
# define REC_ERROR "Not rectanlular map.\n"
# define LETTER_ERROR "Incorect ammount of letters (P,C,E).\n"
# define BLOCKED_ERROR "Exit is blocked.\n"
# define IMAGE_ERROR "One of your sprites could not be opened.\n"


#endif