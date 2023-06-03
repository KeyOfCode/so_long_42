/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:49:44 by darismen          #+#    #+#             */
/*   Updated: 2023/06/02 20:46:40 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
/**
 * @brief Checks the allowed characters
 * 
 */
int	allowed_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(game->map[i][j] == '1' || game->map[i][j] == '0'
				|| game->map[i][j] == 'C' || game->map[i][j] == 'M'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'E'
				|| (j == game->gw - 1 && game->map[i][j] == '\n'))
			)
				return (0);
			if (j == game->gw -1 && game->map[i][j] != '\n' )
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sides_is_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && i < game->gh && j < game->gw - 1)
		{
			if (i == 0 || i + 1 == game->gh)
				if (game->map[i][j] != '1')
					return (0);
			if (j == 0 || j + 2 == game->gw)
				if (game->map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	required_char(t_game *game)
{
	int	i;
	int	j;
	int	check[3];

	i = 0;
	ft_memset(check, 0, sizeof(check));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				check[0]++;
			if (game->map[i][j] == 'C')
				check[1]++;
			if (game->map[i][j] == 'E')
				check[2]++;
			j++;
		}
		i++;
	}
	if (check[0] != 1 || check[1] < 1 || check[2] < 1)
		return (0);
	game->nc = check[1];
	return (1);
}
