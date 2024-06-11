/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:21:13 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/11 16:35:44 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

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




#endif