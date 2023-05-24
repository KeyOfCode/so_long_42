/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:03:43 by darismen          #+#    #+#             */
/*   Updated: 2023/05/24 20:25:33 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	movement(t_game *game, int *pos, char dir)
{
	if (!change_player_dir(game, dir))
		ft_error(4);
	if (!collision(game, pos, dir))
	{
		if (dir == 'D')
			game->img[PLAYER]->instances[0].x += BPX;
		if (dir == 'A')
			game->img[PLAYER]->instances[0].x -= BPX;
		if (dir == 'S')
			game->img[PLAYER]->instances[0].y += BPX;
		if (dir == 'W')
			game->img[PLAYER]->instances[0].y -= BPX;
		return (1);
	}
	else
		return (0);
}

void	movecounter(t_game *game)
{
	game->nm++;
	ft_printf("movement: %d\n", game->nm);
}
