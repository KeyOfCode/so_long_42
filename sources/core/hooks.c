/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:54 by darismen          #+#    #+#             */
/*   Updated: 2023/05/24 20:49:54 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	exit_game(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free(game->map);
	free(game->player);
	free(game);
	ft_printf("\nGame Ended succesfully\n");
	exit(EXIT_SUCCESS);
}

void	hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		pressed;

	game = param;
	pressed = (keydata.action != MLX_RELEASE);
	if (keydata.key == (MLX_KEY_ESCAPE))
		exit_game(game);
	if (keydata.key == MLX_KEY_D && pressed)
		if (movement(game, game->player->pos, 'D'))
			movecounter(game);
	if (keydata.key == MLX_KEY_A && pressed)
		if (movement(game, game->player->pos, 'A'))
			movecounter(game);
	if (keydata.key == MLX_KEY_S && pressed)
		if (movement(game, game->player->pos, 'S'))
			movecounter(game);
	if (keydata.key == MLX_KEY_W && pressed)
		if (movement(game, game->player->pos, 'W'))
			movecounter(game);
}

void	hook_register(t_game *game)
{
	mlx_key_hook(game->mlx, &hooks, game);
}
