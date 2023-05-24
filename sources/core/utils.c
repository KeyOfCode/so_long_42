/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:57:45 by darismen          #+#    #+#             */
/*   Updated: 2023/05/24 20:31:24 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

void	resize_map(t_game *game)
{
	if (!(game->gw * BPX > WIDTH || game->gh * BPX > HEIGHT))
		mlx_set_window_size(game->mlx, (game->gw - 1) * BPX, game->gh * BPX);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i++]);
	}
	printf("\n");
}

void	print_collision(t_game *game, int *pos)
{
	printf("  %c\n", game->map[pos[Y] - 1][pos[X]]);
	printf("%c P  %c\n", game->map[pos[Y]][pos[X] - 1],
		game->map[pos[Y]][pos[X] + 1]);
	printf("  %c\n", game->map[pos[Y] + 1][pos[X]]);
}
