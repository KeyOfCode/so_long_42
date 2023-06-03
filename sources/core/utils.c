/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:57:45 by darismen          #+#    #+#             */
/*   Updated: 2023/06/03 14:11:37 by darismen         ###   ########.fr       */
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

int	ft_2darr_len(void **arr)
{
	int		i;

	i = 0;
	if (arr)
		while (arr[i])
		i++;
	return (i);
}

void	ft_2darrfree(void **arr)
{
	int	len;
	int	i;

	len = ft_2darr_len((void **)arr);
	i = 0;
	while (i < len)
		free(arr[i++]);
	if (arr)
		free(arr);
}