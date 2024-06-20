/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:45:12 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/20 18:07:25 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ch_col_ex_p(t_s *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				game->y = i;
				game->x = j;
			}
			if (game->map[i][j] == 'C')
				game->collectabe++;
			if (game->map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->collectabe < 1 || game->exit > 1)
		exit_error(LETTER_ERROR);
}

void	ch_h_w(t_s *game)
{
	int		i;
	int		j;
	size_t	len;
	size_t	len2;

	i = 0;
	while (game->map[i])
		i++;
	j = 0;
	len = ft_strlen(game->map[j]);
	while (j < i)
	{
		len2 = ft_strlen(game->map[j]);
		if (len != len2 && len > 0)
			exit_error(REC_ERROR);
		j++;
	}
	game->hight = i;
	game->width = len;
}

void	ch_faktors(t_s *game)
{
	ch_h_w(game);
	ch_col_ex_p(game);
	ch_enemy(game);
}

void	check_line(t_s *game)
{
	int	i;
	int	j;

	j = 0;
	if (!game->map)
		exit_error(EMPTY_ERROR);
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] != '1' && game->map[j][i] != 'C'
				&& game->map[j][i] != 'P' && game->map[j][i] != 'E'
				&& game->map[j][i] != '0' && game->map[j][i] != 'e')
				exit_error(SIMB_ERROR);
			i++;
		}
		j++;
	}
	if (i > 100 || j > 100)
		exit_error(WOW_ERROR);
}

void	check_walls(t_s *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (game->map[i] != NULL)
		i++;
	j = 0;
	while (game->map[0][j] != '\0')
	{
		if (game->map[0][j] != '1' || game->map[i - 1][j] != '1')
			exit_error(WALL_ERROR);
		j++;
	}
	k = 0;
	while (k < i)
	{
		j = 0;
		while (game->map[k][j] != '\0')
			j++;
		if (game->map[k][0] != '1' || game->map[k][j - 1] != '1')
			exit_error(WALL_ERROR);
		k++;
	}
}
