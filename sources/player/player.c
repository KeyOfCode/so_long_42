/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:03:43 by darismen          #+#    #+#             */
/*   Updated: 2023/05/05 22:07:54 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player(t_game *game)
{
	game->player->lpp[x] = game->player->pp[x];
	game->player->lpp[y] = game->player->pp[y];
	player_draw(game);
}
