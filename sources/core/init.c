/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:00:57 by darismen          #+#    #+#             */
/*   Updated: 2023/05/01 13:30:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Initialization of the t_so_long structure
void	init_s_so_long(char *argv[], t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	game->lm = 0;
	game->gw = -1;	//Probably not necessary
	game->gh = -1;	//Probably not necessary
	if (argv[2] && ft_strncmp(argv[2], "DEBUG=1", 7) == 0)
		game->dbg = 1;
	else
		game->dbg = 0;
	game->player = ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		exit(EXIT_FAILURE);
	game->player->js = 0;
		//Likely to be removed
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->po[x] = 0;
	game->po[y] = 0;
	game->nm = 0;
	game->lst_map = NULL;
	game->monsters = NULL;
}

int	init_map(int argc, char *argv[], t_game *game)
{
	if (!limit_args(argc, argv))
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
	return (1);
}

// Player initialization
int	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player->tl = 50;
	game->player->nl = LIFE;
	game->player->direction = 1;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player->pp[x] = j * BPX;
				game->player->pp[y] = i * BPX - 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// Camera initialization
void	init_camera(t_game *game)
{
	game->go[x] = 0;
	game->go[y] = 0;
	if (game->gw < 15)
		game->go[x] = (14 - game->gw) / 2 * BPX + 30;
	if (game->gh < 8)
		game->go[y] = (7 - game->gh) / 2 * BPX + 35;
}

/* int	init(t_game *app)
{
	app->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!app->mlx)
		return (false);
	app->img = mlx_new_image(app->mlx, WIDTH / 8, WIDTH / 8);
	ft_line_reader(app);
	memset(app->img->pixels, 255,
		app->img->width * app->img->height * sizeof(int));
	mlx_image_to_window(app->mlx, app->img, 0, 0);
	printf("init: finish.\n");
	return (true);
} */