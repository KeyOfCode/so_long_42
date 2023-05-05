/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:51:36 by darismen          #+#    #+#             */
/*   Updated: 2023/05/01 13:30:32 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int type)
{
	if (type == 1)
		ft_putendl_fd("Error: You must indicate only one map path!", 2);
	if (type == 2)
		ft_putendl_fd("Error: Unable to open the map!", 2);
	if (type == 3)
		ft_putendl_fd("Error: The map is not in a valid format!", 2);
	if (type == 4)
		ft_putendl_fd("Error: A sprite could not be opened !", 2);
	exit(EXIT_SUCCESS);
}

int	openfile(char *filename, t_game *app)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(2);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	init_so_long(argv, game);
	init_map(argc, argv, game);
	init_sprites(game);
	init_player(game);
	init_camera(game);
}

/* int	main(int argc, char	**argv)
{
	t_game	*app;
	int		fd;

	app = NULL;
	if (argc == 2)
	{
		app = (t_game *)malloc(sizeof(t_game));
		fd = openfile(argv[1], app);
		app->fd = fd;
		if (fd < 0)
			exit(EXIT_FAILURE);
		else
		{
			if (init(app))
			{
				mlx_key_hook(app->mlx, &hook, app);
				mlx_loop(app->mlx);
				mlx_terminate(app->mlx);
			}
			else
				mlx_terminate(app->mlx);
		}
	}
	return (1);
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

/* int32_t	main2(void)
{
	t_game	app;

	app.mlx = mlx_init(WIDTH * 5, HEIGHT * 4, "MLX42", true);

	mlx_set_setting(MLX_MAXIMIZED, false);
	if (!app.mlx)
		exit(EXIT_FAILURE);
	app.img = mlx_new_image(app.mlx, 256, 256);
	memset(app.img->pixels, 255,
		app.img->width * app.img->height * sizeof(int));
	mlx_image_to_window(app.mlx, app.img, (WIDTH * 4) / 2, (HEIGHT * 4) / 2);
	mlx_image_to_window(app.mlx, app.img, (WIDTH * 4) / 4, (HEIGHT * 4) / 4);
	mlx_loop_hook(app.mlx, &hook, &app);
	mlx_loop(app.mlx);
	mlx_terminate(app.mlx);
	return (EXIT_SUCCESS);
} */