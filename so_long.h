/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:03:03 by darismen          #+#    #+#             */
/*   Updated: 2024/07/22 16:31:08 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/time.h>

# define BUFFERSIZE 30

# define WIDTH 1280
# define HEIGHT 720

// BPX : bloc px Default is 64
# define BPX 64

/* -Structs- */

/// @brief Structure for the player
/**
 * @param pos : position relative to the map.
 * @param direction : (0 left, 1 right)
*/
typedef struct s_player
{
	int				pos[2];
}	t_player;

/* typedef struct s_player
{
	mlx_instance_t	*instance;
	int				pp[2];
	int				lpp[2];
	int				win_pos[2];
	int				pos[2];
	int				tl[2];
	int				tr[2];
	int				bl[2];
	int				br[2];
	int				ms;
	int				js;
	int				ac[3];
	int				di;
	int				lt;
	int				nl;
	int				direction;
}	t_player; */

typedef enum s_sprites
{
	SPRITES,
	PLAYER = 1,
	GATE,
	COIN,
	OTHER,
	IMG_COUNT
}	t_sprites;

/// @brief Struct that contains all the data of the game
/*!
 * @struct t_game
 * @param mlx : mlx pointer
 * @param img : MLX42 img ppointer, contains each sprite.
 * @param gw 	: game width (number of horizontal tiles)
 * @param gh 	: game height (number of vertical tiles)
 * @param fd 	: file descriptor
 * @param map_fd 	: map file descriptor
 * @param lst_map : *linked list that contains datas map
 * @param map : **map (2D array)
 * @param ps 	: *player sprite
 * @param gs 	: *gate sprite
 * @param ms 	: *monster sprite
 * @param cs 	: *collectable sprite
 * @param os 	: *other sprite
 * @param nc 	: number collectable
 * @param nm 	: number movements
 * @param player 	: *player struct
*/
typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img[IMG_COUNT];
	int					gw;
	int					gh;
	int					fd;
	int					map_fd;
	t_list				*lst_map;
	char				**map;
	mlx_texture_t		*ps[4];
	mlx_texture_t		*gs[2];
	mlx_texture_t		*os[4];
	int					nc;
	int					nm;
	t_player			*player;
}	t_game;

/* typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img[IMG_COUNT];
	int					gw;
	int					gh;
	int					fd;
	int					map_fd;
	t_list				*lst_map;
	char				**map;
	int					dbg;
	mlx_texture_t		*ps[54];
	mlx_texture_t		*gs[2];
	mlx_texture_t		*ms[22];
	mlx_texture_t		*cs[5];
	mlx_texture_t		*os[7];
	long long			lm;
	int					fps;
	int					po[2];
	int					go[2];
	int					nc;
	int					nm;
	t_player			*player;
	t_list				*monsters;
}	t_game;
 */

typedef enum move
{
	X,
	Y,
	xy
}	t_move;

typedef enum dirs
{
	DOWN,
	RIGHT,
	UP,
	LEFT
}	t_dirs;

typedef enum s_others
{
	bg1,
	bg2,
	wall1,
	wall2
}	t_others;

void	hooks(mlx_key_data_t keydata, void *param);

void	ft_error_sl(int type);

/* Init */

void	init_game(t_game *game);
int		init_map(int argc, char *argv[], t_game *game);
int		init_player(t_game *game);
void	init_sprites(t_game *game);
int		find_player_pos(t_game *game);

/* Draw */

void	draw_block(int x, int y, mlx_texture_t *sprite, t_game *game);
void	erase_block(t_game *game, mlx_texture_t *sprite);
void	draw_background(t_game *game);
void	draw_player(t_game *game);
int		change_player_dir(t_game *game, char dir);
void	draw_other(t_game *game);

/* Hooks */

void	hook_register(t_game *game);
void	exit_game(t_game *game);

/* Parsing */

int		open_map(char *relative_path, t_game *game);
int		fill_lst(t_game *game);
int		convert_lst(t_game *game);
int		size_check(t_game *game);
int		allowed_char(t_game *game);
int		sides_is_wall(t_game *game);
int		required_char(t_game *game);
int		path_to_exit(t_game *game);

/* Player */
int		movement(t_game *game, int *pos, char dir);
void	movecounter(t_game *game);
int		collision(t_game *game, int pos[2], char dir);
void	coin_collision(t_game *game, int pos[2]);
void	gate_collision(t_game *game, int *pos);

/* Utils */
void	fps(t_game *game);
void	resize_map(t_game *game);
int		ft_2darr_len(void **arr);
void	ft_2darrfree(void **arr);
//long long	militimestamp(void);

#endif