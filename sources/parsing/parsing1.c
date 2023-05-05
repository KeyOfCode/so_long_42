/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:19:18 by darismen          #+#    #+#             */
/*   Updated: 2023/05/03 22:48:51 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	open_map(char *relative_path, t_game *game)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(&relative_path[path_len - 4], ".ber", 4) != 0)
		return (0);
	game->map_fd = open(relative_path, O_RDONLY);
	if (game->map_fd < 0)
		return (0);
	return (1);
}

/* Find out what does gw and gh do*/
int	fill_lst(t_game *game)
{
	char	*line;

	line = "";
	while (game->fd)
	{
		line = get_next_line(game->map_fd);
		if (line == NULL)
		{
			if (game->gw == -1)
				return (0);
			return (1);
		}
	}
}

/* 
gh seems to be the height of the map, independet of the
Height of the screen. 
3 lines is the minimum height for a game.
Allways allocate memory for + 1 to avoid segfaults.

How can game->gh = ft_lstsize(game->lst_map); be valid if I'm 
parsing the map right now??
*/
int	convert_lst(t_game *game)
{
	t_list	*lst;
	int		i;

	game->gh = ft_lstsize(game->lst_map);
	if (game->gh < 3)
		return (0);
	game->map = ft_calloc(game->gh + 1, sizeof(char *));
	if (game->map)
		exit(EXIT_FAILURE);
	lst = game->lst_map;
	i = 0;
	while (lst)
	{
		game->map[i] = ft_strdup(lst->content);
		if (game->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	game->gw = ft_strlen(game->map[0]);
	if (game->gw < 4)
		return (0);
	return (1);
}

int	size_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i < game->gh)
			return (0);
		if (i + 1 == game->gh && \
			(int)ft_strlen(game->map[i]) == game->gw - 1)
			return (1);
		if ((int)ft_strlen(game->map[i]) != game->gw)
			return (0);
		i++;
	}
	return (1);
}
