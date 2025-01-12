/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:52:27 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 13:33:09 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	is_tile_exit(t_game *game, char tile)
{
	if (tile == 'O')
	{
		ft_putstr("Congratulation you win !!!!!!!!");
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
}

void	if_tile_is_col_or_exit(char tile, t_game *game, int new_x, int new_y)
{
	static int	collected_items;
	int			x;
	int			y;

	y = 0;
	if (tile == 'C')
	{
		collected_items++;
		game->map[new_y][new_x] = '0';
		if (collected_items == game->total_coll)
		{
			while (y < game->map_height)
			{
				x = 0;
				while (x < game->map_width)
				{
					if (game->map[y][x] == 'E')
						game->map[y][x] = 'O';
					x++;
				}
				y++;
			}
		}
	}
	is_tile_exit(game, tile);
}

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	char	tile;

	if (new_x < 0 || new_y < 0 || new_x >= game->map_width
		|| new_y >= game->map_height)
		return (0);
	tile = game->map[new_y][new_x];
	if (tile == '1')
		return (0);
	if (tile == 'E')
		return (0);
	if_tile_is_col_or_exit(tile, game, new_x, new_y);
	return (1);
}
