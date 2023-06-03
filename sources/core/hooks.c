/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:54 by darismen          #+#    #+#             */
/*   Updated: 2023/06/03 13:57:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

void	ft_free_textures(t_game *game)
{
	int	i;
	i = 0;
	while (i < 4)
		{printf("other sprite: %p\n", game->os[i]); mlx_delete_texture(game->os[i++]);}
	i = 0;
	while (i < 4)
		{printf("player sprite: %p\n", game->ps[i]); mlx_delete_texture(game->ps[i++]);}
	i = 0;
	while (i < 2)
		{printf("gate sprite: %p\n", game->gs[i]); mlx_delete_texture(game->gs[i++]);}
	i = 0;
	if (game->nc != 0)
		printf("coin sprite: %p\n", game->img[COIN]); mlx_delete_image(game->mlx, game->img[COIN]);
	while (i < IMG_COUNT)
		if (game->img[i])
			mlx_delete_image(game->mlx, game->img[i++]);
}


void	exit_game(t_game *game)
{
	printf("game pointer: %p\n", game);
	printf("player pointer: %p\n", game->player);
	mlx_close_window(game->mlx);
	ft_free_textures(game);
	mlx_terminate(game->mlx);
	ft_2darrfree((void **)game->map);
	ft_lstclear(&game->lst_map, free);
	free(game->player);
	free(game);
	printf("BREAK!\n");	
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
