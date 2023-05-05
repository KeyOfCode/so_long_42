/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:36:17 by darismen          #+#    #+#             */
/*   Updated: 2023/05/05 21:39:18 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*path_to_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin("./textures/", sprite_name);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, sprite_name);
	free(str2);
	str2 = ft_strjoin(str1, "_");
	free(str1);
	str1 = ft_strjoin(str2, nbr);
	free(str2);
	str2 = ft_strjoin(str1, ".png");
	free(str1);
	free(nbr);
	return (str2);
}

void	load_sprite_type(int i, char *p, int sprite_type,
		t_game *game)
{
	if (sprite_type == PLAYER)
		game->ps[i] = mlx_load_png(p);
	else if (sprite_type == MONSTER)
		game->ms[i] = mlx_load_png(p);
	else if (sprite_type == GATE)
		game->gs[i] = mlx_load_png(p);
	else if (sprite_type == COIN)
		game->cs[i] = mlx_load_png(p);
	else if (sprite_type == OTHER)
		game->os[i] = mlx_load_png(p);
	if (!(game->ps[i] || game->ms[i] || game->gs[i]
			|| game->cs[i] || game->os[i]))
		ft_error(4);
}

/**
* @param	nb_sprite : it points to each frame of their animations.
* @param	fd : checks if the sprite exists.
*/
void	load_sprite(char *sprite_name, int nb_sprite,
	int sprite_type, t_game *game)
{
	int		i;
	char	*path;
	int		fd;

	i = 0;
	while (i++ < nb_sprite)
	{
		path = path_to_sprite(sprite_name, i - 1);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			ft_error(4);
		close(fd);
		load_sprite_type(i - 1, path, sprite_type, game);
		free(path);
	}
}

// All sprites initialization. The second argument is the number of
//sprites each type has.
void	init_sprites(t_game *game)
{
	load_sprite("other", 7, OTHER, game);
	load_sprite("player", 54, PLAYER, game);
	load_sprite("enemy", 22, MONSTER, game);
	load_sprite("gate", 4, GATE, game);
	load_sprite("coin", 5, COIN, game);
}
