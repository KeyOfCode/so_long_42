/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:09:27 by darismen          #+#    #+#             */
/*   Updated: 2023/06/03 13:13:24 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/**
 * @brief Checks if there's a wall in the direction is moving. 
 * If not, update position variable
 * (placed here due to function size issues...)
 * 
 * @param game 
 * @param pos 
 * @param dir 
 * @return int 
 */
int	wall_collision(t_game *game, int *pos, char dir)
{
	if (dir == 'S' && !(game->map[pos[Y] + 1][pos[X]] == '1'))
	{
		pos[Y]++;
		return (0);
	}
	if (dir == 'W' && !(game->map[pos[Y] - 1][pos[X]] == '1'))
	{
		pos[Y]--;
		return (0);
	}
	if (dir == 'D' && !(game->map[pos[Y]][pos[X] + 1] == '1'))
	{
		pos[X]++;
		return (0);
	}
	if (dir == 'A' && !(game->map[pos[Y]][pos[X] - 1] == '1'))
	{
		pos[X]--;
		return (0);
	}
	return (1);
}

void	coin_collision(t_game *game, int pos[2])
{
	game->map[pos[Y]][pos[X]] = '0';
	game->nc--;
	draw_block(pos[X] * BPX, pos[Y] * BPX, game->os[bg1], game);
	draw_player(game);
}

void	gate_collision(t_game *game, int *pos)
{
	int	x;
	int	y;

	x = game->img[GATE]->instances->x;
	y = game->img[GATE]->instances->y;
	if (game->nc == 0)
		draw_block(x, y, game->gs[1], game);
	if (game->map[pos[Y]][pos[X]] == 'E'
		&& game->nc == 0)
		exit_game(game);
}

int	collision(t_game *game, int pos[2], char dir)
{
	if (!(wall_collision(game, pos, dir)))
		return (0);
	else
		return (1);
}
