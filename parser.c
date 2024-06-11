/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:45:12 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/11 19:21:53 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


////// проверить флудфилом возможность добраться до выхода
////// 


#include "so_long.h"

void    ch_col_ex_p(char **map, t_s *game)
{
    int    i;
    int    j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                game->player++;
            if (map[i][j] == 'C')
                game->collectabe++;
        	if (map[i][j] == 'E')
				game->exit++;
            j++;
        }
        i++;
        game->y++;
    }
    if (game->player != 1 || game->collectabe < 1 || game->exit > 1)
        exit (5);
}

void    ch_h_w(char **map, t_s *game){
    int    i;
    int    j;
    size_t len;
    size_t len2;

    i = 0;
    while (map[i])
        i++;
    j = 0;
    len = ft_strlen(map[j]);
	game->x = (int)len;
    while (j < i)
    {
        len2 = ft_strlen(map[j]);
        if (len != len2 && len > 0)
            exit (4);
        j++;
    }
    game->hight = i;
    game->width = len;
}

void    ch_faktors(char **map, t_s *game){
    ch_h_w(map, game);
    ch_col_ex_p(map, game);
}

void	check_line(char **line)
{
	int	i;
	int	j;

	j = 0;
	while (line[j] != NULL)
	{
		printf("%s-\n", line[j]);
		i = 0;
		while (line[j][i] != '\0')
		{
			if (line[j][i] != '1' && line[j][i] != 'C' && line[j][i] != 'P' && line[j][i] != 'E' && line[j][i] != '0')
				exit (8);
			i++;
		}
		j++;
	}
}

void check_walls(char **map)
{
    int i = 0;
    int j;

    while (map[i] != NULL)
        i++;

    j = 0;
    while (map[0][j] != '\0')
    {
        if (map[0][j] != '1' || map[i - 1][j] != '1')
            exit(9);
        j++;
    }

    int k = 0;
    while (k < i)
    {
        j = 0;
        while (map[k][j] != '\0')
            j++;
        if (map[k][0] != '1' || map[k][j - 1] != '1')
            exit(9);
        k++;
    }
}

void    check_map(t_s *game, int fd)
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
}

t_s      new_init(void)
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

t_s      *init(char **av, t_s *game)
{
	int	fd;
	
	fd = open(av[1], O_RDONLY);
    if (fd < 0)
        exit (1);
    *game = new_init();
    check_map(game, fd);
    write(1, "NICE\n", 5);
    return (game);
}

int main(int ac, char **av){
    t_s game;

    if (ac != 2)
        return (11);
    init(av, &game);
    printf("%d-coll, %d-exit, %d-player, %d-hight, %d-width, %d-x, %d-y\n", game.collectabe, game.exit, game.player, game.hight, game.width, game.x, game.y);
    return (0);
}
