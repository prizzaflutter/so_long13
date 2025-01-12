/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:22:15 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 13:37:48 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*init_map(t_game *game, char *file_path, int fd)
{
	int		map_height;
	char	*line;

	map_height = get_map_heigth(file_path);
	game->map = (char **)malloc((map_height + 1) * sizeof(char *));
	if (!game->map)
		return (NULL);
	game->map_height = map_height;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	game->map_width = get_map_width(line);
	return (line);
}
