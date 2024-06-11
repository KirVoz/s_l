/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:47:25 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/11 14:42:35 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ch_col_ex_p(char **map, t_s game){
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				game.player++;
			if (map[i][j] == 'C')
				game.collectabe++;
			if (map[i][j] == 'E')
				game.exit++;	
			j++;
			game.x++;
		}
		i++;
		game.y++;
	}
	if (game.player != 1 || game.collectabe < 1 || game.exit > 1)
		exit (5);
}

void	ch_h_w(char **map, t_s game){
	int	i;
	int	j;
	size_t len;
	size_t len2;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	len = ft_strlen(map[j]);
	while (j <= i)
	{
		len2 = ft_strlen(map[j]);
		if (len != len2 && len > 0)
			exit (4);
		j++;
	}
	game->hight = i + 1;
	game->width = len;
}

void	ch_faktors(char **map, t_s game){
	ch_h_w(map, game);
	ch_col_ex_p(map, game);
	
}

void	check_map(char **av, t_s game){
	int fd;
	char *line;
	char **map_line;
	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit (1);
	line = get_next_line(fd);
	if (!line)
		exit (2);
	map_line = ft_split(line, '\n');
	free(line);
	ch_faktors(map_line, game);
}

t_s	new_init(void)
{
	t_s game;
	// game = malloc(sizeof(t_s));
	
	game.collectabe = 0;
	game.exit = 0;
	game.hight = 0;
	game.player = 0;
	game.width = 0;
	game.x = 0;
	game.y = 0;
	return (game);
}

t_s	*init(char **av, t_s game){
	game = new_init();
	printf("fuck\n");
	check_map(av, game);
	write(1, "NICE\n", 5);
	return (game);
}

int main(int ac, char **av){
	t_s game;
	
	game = NULL;
	if (ac != 2)
		return (11);
	game = init(av, game);
	printf("%d-coll, %d-exit, %d-player, %d-hight, %d-width, %d-x, %d-y\n", game->collectabe, game->exit, game->player, game->hight, game->width, game->x, game->y);
}