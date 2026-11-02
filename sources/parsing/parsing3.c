/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:19:18 by darismen          #+#    #+#             */
/*   Updated: 2026/11/02 15:42:11 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_map_size(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

/**
 * @brief Make a copy of the game->map
 * 
 * @param map game->map
 * @return char** 
 */
char	**ft_map_copy(char **map)
{
	char	**copy;
	int		i;

	copy = ft_calloc(ft_map_size(map) + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

void	ft_map_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}



/**
 * @brief	Recursively fills the map with 'y' in each direction 
 * 			starting from the player.
 * 			If path_to_Exit finds anything other than 'y', it returns 0
 * 
 * @param map to_fill: copy of the map
 * @param pos_y y coordinate of the player and later calls
 * @param pos_x x coordinate of the player and later calls
 */
void	ft_fill(char **map, int pos_y, int pos_x)
{
	map[pos_y][pos_x] = 'y';
	if (is_fillable(map[pos_y - 1][pos_x]))
		ft_fill(map, pos_y - 1, pos_x);
	if (is_fillable(map[pos_y + 1][pos_x]))
		ft_fill(map, pos_y + 1, pos_x);
	if (is_fillable(map[pos_y][pos_x + 1]))
		ft_fill(map, pos_y, pos_x + 1);
	if (is_fillable(map[pos_y][pos_x - 1]))
		ft_fill(map, pos_y, pos_x - 1);
}

/**
 * @brief	Checks that there's a path from the player to the exit.
 * 			I have to find the player's position first.
 * 
 * @param game 
 * @return int 
 */
int	path_to_exit(t_game *game)
{
	char	**to_fill;
	int		i;
	int		j;

	to_fill = ft_map_copy(game->map);
	if (!find_player_pos(game))
		return (0);
	ft_fill(to_fill, game->player->pos[Y], game->player->pos[X]);
	i = 0;
	while (to_fill[i])
	{
		j = 0;
		while (to_fill[i][j])
		{
			if (to_fill[i][j] == 'E' || to_fill[i][j] == 'C')
				return (ft_map_free(to_fill), 0);
			j++;
		}
		i++;
	}
	return (ft_map_free(to_fill), 1);
}
