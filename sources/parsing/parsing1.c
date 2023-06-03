/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:19:18 by darismen          #+#    #+#             */
/*   Updated: 2023/06/02 22:00:06 by darismen         ###   ########.fr       */
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

int	fill_lst(t_game *game)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(game->map_fd);
		if (line == NULL)
		{
			if (game->gw == -1)
				return (0);
			return (1);
		}
		if (game->gw == -1)
			game->gw = (int)ft_strlen(line) - 1;
		if (game->lst_map == NULL)
			game->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&game->lst_map, ft_lstnew(line));
	}
	free(line);
	return (1);
}

/**
 * @brief 
 * 
 * @param game_gh	game height, how many cells high is the map. 
 * @param game_gw	game width, how many cells wide is the map. 
 * @return	Returns 0 if gw < 4, the minimun space for two walls, 
 * 			the player, a coin and the gate.
			Returns 1 otherwise 
 */
int	convert_lst(t_game *game)
{
	t_list	*lst;
	int		i;

	game->gh = ft_lstsize(game->lst_map);
	if (game->gh < 3)
		return (0);
	game->map = ft_calloc(game->gh + 1, sizeof(char *));
	if (!game->map)
		exit(EXIT_FAILURE);
	lst = game->lst_map;
	i = 0;
	while (lst)
	{
		game->map[i] = ft_strdup(lst->content);
		if (!game->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	game->gw = ft_strlen(game->map[0]);
	if (game->gw < 4)
		return (0);
	return (1);
}

/**
* @result Returns 0 if i reads more lines that the gh or if the 
			current line is not equal to gw.
			It returns 1 if i it's equal to gw - 1 
 */
int	size_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i > game->gh)
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
