/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:09:27 by darismen          #+#    #+#             */
/*   Updated: 2023/06/02 20:46:59 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player->pos[X] * BPX;
	y = game->player->pos[Y] * BPX;
	mlx_image_to_window(game->mlx, game->img[PLAYER], x, y);
}

/**
 * @brief Changes the player image in the buffer when it changes direction
 * 
 * @param game 
 * @param dir 
 * @return int 
 */
int	change_player_dir(t_game *game, char dir)
{
	mlx_delete_image(game->mlx, game->img[PLAYER]);
	if (dir == 'D')
		game->img[PLAYER] = mlx_texture_to_image(game->mlx, game->ps[RIGHT]);
	if (dir == 'A')
		game->img[PLAYER] = mlx_texture_to_image(game->mlx, game->ps[LEFT]);
	if (dir == 'S')
		game->img[PLAYER] = mlx_texture_to_image(game->mlx, game->ps[DOWN]);
	if (dir == 'W')
		game->img[PLAYER] = mlx_texture_to_image(game->mlx, game->ps[UP]);
	if (!(game->img[PLAYER]))
		return (0);
	else
		draw_player(game);
	return (1);
}
