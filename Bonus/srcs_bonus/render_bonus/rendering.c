/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:54:36 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/13 12:35:33 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	*render_images(char x_y, t_game *game, int x, int y)
{
	char	*img_to_draw;

	img_to_draw = NULL;
	if (x_y == '1')
		img_to_draw = game->wall_img;
	else if (x_y == '0')
		img_to_draw = game->background_img;
	else if (x_y == 'C')
		img_to_draw = game->collectible_img;
	else if (x_y == 'E')
		img_to_draw = game->close_exit_img;
	else if (x_y == 'N')
		img_to_draw = game->frames[game->current_frame];
	else if (x_y == 'P')
	{
		if (x == game->player_x && y == game->player_y)
			img_to_draw = game->player_img;
		else
			img_to_draw = game->background_img;
	}
	else
		img_to_draw = game->open_exit_img;
	return (img_to_draw);
}


int	render_map(t_game	*game)
{
	int		tile_size;
	int		x;
	char	*img_to_draw;
	int		y;

	y = 0;
	tile_size = 32;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x])
		{
			img_to_draw = render_images(game->map[y][x], game, x, y);
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				img_to_draw, x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->background_img,
		game->player_x * tile_size, game->player_y * tile_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img,
		game->player_x * tile_size, game->player_y * tile_size);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0x00FF0000,
		ft_itoa(game->total_moves));
	return (1);
}
