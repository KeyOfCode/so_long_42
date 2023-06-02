/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:00:57 by darismen          #+#    #+#             */
/*   Updated: 2023/06/02 19:42:21 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Initialization of the t_game structure
void	init_game(char **argv, t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		ft_error(5);
	game->lm = 0;
	game->gw = -1;
	game->gh = -1;
	if (argv[2] && ft_strncmp(argv[2], "DEBUG=1", 7) == 0)
		game->dbg = 1;
	else
		game->dbg = 0;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit(EXIT_FAILURE);
	game->player->js = 0;
	game->img[0] = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->po[X] = 0;
	game->po[Y] = 0;
	game->nm = 0;
	game->lst_map = NULL;
	game->monsters = NULL;
}

int	init_map(int argc, char *argv[], t_game *game)
{
	if (argc != 2)
		ft_error(1);
	if (!open_map(argv[1], game))
		ft_error(2);
	if (!fill_lst(game))
		ft_error(3);
	if (!convert_lst(game))
		ft_error(3);
	if (!size_check(game))
		ft_error(3);
	if (!allowed_char(game))
		ft_error(3);
	if (!sides_is_wall(game))
		ft_error(3);
	if (!required_char(game))
		ft_error(3);
	if (!path_to_exit(game))
		ft_error(3);
	return (1);
}

int	find_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player->pp[X] = j * BPX;
				game->player->pp[Y] = i * BPX - 1;
				game->player->pos[X] = j;
				game->player->pos[Y] = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	init_player(t_game *game)
{
	game->img[PLAYER] = mlx_texture_to_image(game->mlx, game->ps[DOWN]);
	return (find_player_pos(game));
}
