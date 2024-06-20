/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:21:13 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 18:30:58 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct pointers
{
	void	*mlx;
	void	*window;
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
	void	**bonus_background;
	void	**enemy_up;
	void	**enemy_right;
	void	**enemy_down;
	void	**enemy_left;
	void	**enemy_still;
}			t_s_p;

typedef struct s_struct
{
	int		loop;
	int		enemy;
	int		x_e;
	int		y_e;
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
	char	**map;
	t_s_p	point;
}			t_s;

// end_game_options.c
int			end_game(t_s *game);
void		free_map(char **map);
// enemy.c
void		ch_enemy(t_s *game);
bool		is_wall_enemy(t_s *game, int direction);
void		put_image_enemy(t_s *game, void **image, int direction);
void		move_enemy(t_s *game, void **player, int direction);
int			enemy(t_s *game);
// flood_fill.c
char		**create_map_copy(t_s *game);
void		flood(char **map, int y, int x, t_s *game);
void		flo_fil(char **map, int y, int x, t_s *game);
bool		exit_flood(t_s *game);
void		flood_fill(t_s *game);
// init.c
void		check_norm(t_s *game);
void		check_map(t_s *game, int fd);
t_s_p		init_pointers(void);
t_s			new_init(void);
t_s			*init(char **av, t_s *game);
// move_helper.c
void		change_location_on_map(t_s *game, int direction, int option);
void		is_win(t_s *game, void **player, void **exit, int direction);
bool		is_exit(t_s *game, int direction);
bool		is_wall(t_s *game, int direction);
void		check_if_collectible(t_s *game);
// moves.c
void		put_moves(t_s *game);
void		move(t_s *game, void **player, int direction);
int			key_managment(int keycode, t_s *game);
void		change_enemy_location_on_map(t_s *game, int direction, int option);
// parser.c
void		ch_col_ex_p(t_s *game);
void		ch_h_w(t_s *game);
void		ch_faktors(t_s *game);
void		check_line(t_s *game);
void		check_walls(t_s *game);
// put_images.c
void		put_image(t_s *game, void **image, int x, int y);
void		put_image_direction(t_s *game, void **image, int direction);
void		destroy_if_not_null(t_s *game, void **image);
void		destroy_images(t_s *game);
// so_long.c
void		exit_error(char *error);
void		start_game(t_s *game);
// start_game.c
void		**xpm_image(t_s *game, char *path);
void		init_xpms(t_s *game);
void		init_map_images(t_s *game);

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# define ENTER 36
# define ESC 53

# define SIZE 32

# define TRUE 0 // ground
# define FALSE 1 // wall

# define BER_ERROR "Not '.ber' extension.\n"
# define ARG_ERROR "Incorrect amount of arguments.\n"
# define FD_ERROR "FD Error.\n"
# define COLL_ERROR "Can't reach all collectables.\n"
# define EX_ERROR "Can't reach Exit.\n"
# define WALL_ERROR "No border walls.\n"
# define SIMB_ERROR "Forbidden symbols on map.\n"
# define REC_ERROR "Not rectangular map.\n"
# define LETTER_ERROR "Incorrect amount of letters (P,C,E).\n"
# define BLOCKED_ERROR "Exit is blocked.\n"
# define IMAGE_ERROR "One of your sprites could not be opened.\n"
# define EMPTY_ERROR "Map ERROR.\n"
# define WOW_ERROR "Stop breaking my game plz).\n"
# define ENEMY_ERROR "One enemy is enough"

#endif