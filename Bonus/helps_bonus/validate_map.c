/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:16:19 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 13:37:52 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	validate_map(char *next_line, char *line, int fd, t_game *game)
{
	if (is_rectangular(line) == 0)
		return (0);
	if (!next_line && is_map_closed_by_walls(line, 1) == 0)
		return (close(fd), 0);
	else if (next_line && is_map_closed_by_walls(line, 0) == 0)
		return (close(fd), 0);
	if (!next_line)
	{
		if (how_many(line, 1) == 0)
			return (close(fd), 0);
		else
			game->total_coll = how_many(line, 1);
	}
	else
		how_many(line, 0);
	if (is_something_inside_map(line) == 0)
		return (close(fd), 0);
	return (1);
}
