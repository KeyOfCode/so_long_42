/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:54 by darismen          #+#    #+#             */
/*   Updated: 2023/05/01 13:30:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_game	*app;

	app = param;
	printf("Key-hook: succesful.\n");
	if (keydata.key == (MLX_KEY_ESCAPE))
		mlx_terminate(app->mlx);
	if (keydata.key == (MLX_KEY_UP))
		app->img->instances[0].y -= 10;
	if (keydata.key == (MLX_KEY_DOWN))
		app->img->instances[0].y += 10;
	if (keydata.key == (MLX_KEY_LEFT))
		app->img->instances[0].x -= 10;
	if (keydata.key == (MLX_KEY_RIGHT))
		app->img->instances[0].x += 10;
}

void	close_hook(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == (MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		free(game->map);
		free(game->player);
		free(game);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	hook_register(t_game *game)
{
	mlx_key_data_t	keydata;
/* 	mlx_loop_hook();
	mlx_key_hook(); */
	mlx_close_hook(game->mlx, close_hook, game);
}

/* void	hook(mlx_key_data_t keydata, void *param)
{
	t_game	*app;

	app = param;
	if (keydata.key == (MLX_KEY_ESCAPE))
		mlx_terminate(app->mlx);
	if (keydata.key == (MLX_KEY_UP))
		app->img->instances[0].y -= 10;
	if (keydata.key == (MLX_KEY_DOWN))
		app->img->instances[0].y += 10;
	if (keydata.key == (MLX_KEY_LEFT))
		app->img->instances[0].x -= 10;
	if (keydata.key == (MLX_KEY_RIGHT))
		app->img->instances[0].x += 10;
} */

/* void	hook(void *param)
{
	t_game	*app;

	app = param;
	if (mlx_is_key_down(app->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(app->mlx);
	if (mlx_is_key_down(app->mlx, MLX_KEY_UP))
		app->img->instances[0].y -= 10;
	if (mlx_is_key_down(app->mlx, MLX_KEY_DOWN))
		app->img->instances[0].y += 10;
	if (mlx_is_key_down(app->mlx, MLX_KEY_LEFT))
		app->img->instances[0].x -= 10;
	if (mlx_is_key_down(app->mlx, MLX_KEY_RIGHT))
		app->img->instances[0].x += 10;
} */