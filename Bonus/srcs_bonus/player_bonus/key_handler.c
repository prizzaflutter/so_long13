/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:59:07 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/13 12:34:06 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"
#include <stdio.h>

int	key_handler(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	else if (keycode == 13)
		new_y -= 1;
	else if (keycode == 1)
		new_y += 1;
	else if (keycode == 0)
		new_x -= 1;
	else if (keycode == 2)
		new_x += 1;
	if (is_valid_move(game, new_x, new_y))
	{
		game->total_moves++;
		game->player_x = new_x;
		game->player_y = new_y;
	}
	render_map(game);
	return (0);
}
