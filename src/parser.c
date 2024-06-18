/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:45:12 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/18 18:26:21 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ch_col_ex_p(char **map, t_s *game)
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
            {
				game->player++;
				game->y = i;
				game->x = j;
			}
            if (map[i][j] == 'C')
                game->collectabe++;
        	if (map[i][j] == 'E')
				game->exit++;
            j++;
        }
        i++;
    }
    if (game->player != 1 || game->collectabe < 1 || game->exit > 1)
        exit_error (LETTER_ERROR);
}

void	ch_h_w(char **map, t_s *game)
{
    int    i;
    int    j;
    size_t len;
    size_t len2;

    i = 0;
    while (map[i])
        i++;
    j = 0;
    len = ft_strlen(map[j]);
    while (j < i)
    {
        len2 = ft_strlen(map[j]);
        if (len != len2 && len > 0)
            exit_error (REC_ERROR);
        j++;
    }
    game->hight = i;
    game->width = len;
}

void	ch_faktors(char **map, t_s *game)
{
    ch_h_w(map, game);
    ch_col_ex_p(map, game);
	ch_enemy(map, game);
}

void	check_line(char **line)
{
	int	i;
	int	j;

	j = 0;
	while (line[j] != NULL)
	{
		i = 0;
		while (line[j][i] != '\0')
		{
			if (line[j][i] != '1' && line[j][i] != 'C' && line[j][i] != 'P' 
			&& line[j][i] != 'E' && line[j][i] != '0' && line[j][i] != 'e')
				exit_error (SIMB_ERROR);
			i++;
		}
		j++;
	}
}

void	check_walls(char **map)
{
    int i = 0;
    int j;

    while (map[i] != NULL)
        i++;

    j = 0;
    while (map[0][j] != '\0')
    {
        if (map[0][j] != '1' || map[i - 1][j] != '1')
            exit_error (WALL_ERROR);
        j++;
    }

    int k = 0;
    while (k < i)
    {
        j = 0;
        while (map[k][j] != '\0')
            j++;
        if (map[k][0] != '1' || map[k][j - 1] != '1')
            exit_error (WALL_ERROR);
        k++;
    }
}
