/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:03:03 by darismen          #+#    #+#             */
/*   Updated: 2023/05/05 22:28:08 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/time.h>

# define BUFFERSIZE 30

# define WIDTH 1920
# define HEIGHT 1080
# define PX_SIZE 16
# define LIFE 16

/*
BPX : bloc px
MPX : movement px
GPX : ground px
JPX : jump px
HPX : hitbox px
EHPX : extra hitbox
*/
# define BPX 100
# define MPX 8
# define GPX 14
# define DPX 20
# define JPX 40
# define HPX 15
# define EHPX 25

/* -Structs- */

/// @brief Structure for the player
/**
*@param pp : pixel position (pp[0] : x, pp[1] : y)
*@param lpp : last pixel position (lpp[0] : x, lpp[1] : y)
*@param a : top left		(a[0] : x, a[1] : y)
*@param b : top right		(b[0] : x, b[1] : y)
*@param c : bottom left 	(c[0] : x, c[1] : y)
*@param d : bottom right 	(d[0] : x, d[1] : y)
*@param js : jump state
*@param ac : actions code
*@param di : diagonal (1 : left, 2 : right)
*@param tl : tick life
*@param nl : life number
*@param direction : (0 left, 1 right)
*/
typedef struct s_player
{
	int	pp[2];
	int	lpp[2];
	int	a[2];
	int	b[2];
	int	c[2];
	int	d[2];
	int	js;
	int	ac[3];
	int	di;
	int	tl;
	int	nl;
	int	direction;
}	t_player;

/// @brief Struct that contains all the data of the game
/**
*@param mlx : mlx pointer
*@param img : MLX42 img pointer
*@param gw 	: game width
*@param gh 	: game height
*@param fd 	: file descriptor
*@param map_fd 	: map file descriptor
*@param lst_map : *linked list that contains datas map
*@param map : **map (2D array)
*@param dbg : Flag for debugging
*@param ps 	: *player sprite
*@param gs 	: *gate sprite
*@param ms 	: *monster sprite
*@param cs 	: *collectable sprite
*@param os 	: *other sprite
*@param lm 	: last millitimestamp
*@param fps : frame per second
*@param po 	: player offset
*@param go 	: global offset
*@param nc 	: number collectable
*@param nm 	: number movements
*@param player 	: *player struct
*@param monster : *monster struct
*/
typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			gw;
	int			gh;
	int			fd;
	int			map_fd;
	t_list		*lst_map;
	char		**map;
	int			dbg;
	void		*ps[54];
	void		*gs[5];
	void		*ms[22];
	void		*cs[5];
	void		*os[7];
	long long	lm;
	int			fps;
	int			po[2];
	int			go[2];
	int			nc;
	int			nm;
	t_player	*player;
	t_list		*monsters;
}	t_game;

typedef enum move
{
	x,
	y,
	xy
}	t_move;

typedef struct coords
{
	size_t	x_start;
	size_t	x_end;
	size_t	y_start;
	size_t	y_end;
	int32_t	instance;
}	t_coords;

typedef enum s_sprites
{
	PLAYER = 1,
	MONSTER,
	GATE,
	COIN,
	OTHER
}	t_sprites;

typedef enum s_others
{
	bg1,
	bg2,
	wall,
}	t_others;

void	hook(mlx_key_data_t keydata, void *param);

void	ft_error(int type);

/* Init */

void	init_s_so_long(char *argv[], t_game *game);
int		init_map(int argc, char *argv[], t_game *game);
int		init_player(t_game *game);
void	init_camera(t_game *game);

/* Draw */

void	draw_block(int x, int y, void *sprite, t_game *game);

#endif