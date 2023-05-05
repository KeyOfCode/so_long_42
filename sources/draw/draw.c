/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:28:29 by darismen          #+#    #+#             */
/*   Updated: 2023/05/01 13:35:03 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_block(int x, int y, void *sprite, t_game *game)
{
	if (x < -BPX || y < -BPX || x > WIDTH || y < HEIGHT)
		return ;
	mlx_image_to_window(game->mlx, sprite,
		x + game->go[x], y + game->go[y]);
}
