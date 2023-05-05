/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:09:27 by darismen          #+#    #+#             */
/*   Updated: 2023/05/05 22:28:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->gh)
	{
		j = 0;
		while (j < game->gw)
		{
			if (game->map[i][j] == '1')
				draw_block(j * BPX + game->po[x], i * BPX + game->po[y],
					game->os[wall], game);
			j++;
		}
		i++;
	}
}
