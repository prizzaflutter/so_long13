/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:53:04 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 14:15:39 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	fill_map(t_game	*game, char	*line, int fd, int *y)
{
	int	x;

	game->map[*y] = (char *)malloc(get_map_width(line) * sizeof(char));
	if (!game->map[*y])
		return (free(line), close(fd), 0);
	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] == 'P')
		{
			game->player_x = x;
			game->player_y = *y;
		}
		game->map[*y][x] = line[x];
		x++;
	}
	game->map[*y][x] = '\0';
	return (1);
}
