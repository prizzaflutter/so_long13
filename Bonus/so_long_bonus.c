/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:28:03 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/13 12:27:47 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

void	init_countre(t_copy *copy)
{
	copy->countre_c = 0;
	copy->countre_e = 0;
}

t_copy	copy_map(t_game *game)
{
	int		i;
	int		j;
	t_copy	copy;

	copy.map_width = game->map_width;
	copy.map_height = game->map_height;
	copy.map = malloc(sizeof(char *) * (copy.map_height + 1));
	if (!copy.map)
		return (copy);
	i = 0;
	while (i < game->map_height)
	{
		copy.map[i] = malloc(sizeof(char) * game->map_width + 1);
		j = 0;
		while (j < game->map_width)
		{
			copy.map[i][j] = game->map[i][j];
			j++;
		}
		copy.map[i][j] = '\0';
		i++;
	}
	copy.map[i] = NULL;
	init_countre(&copy);
	return (copy);
}

void	is_success(t_copy *copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= copy->map_width || y >= copy->map_height)
		return ;
	if (copy->map[y][x] == '1' || copy->map[y][x] == 'v' || copy->map[y][x] == 'N'
		|| (copy->map[y][x] == 'E' && copy->countre_e == 1))
		return ;
	if (copy->map[y][x] == 'E')
		copy->countre_e++;
	if (copy->map[y][x] == 'C')
		copy->countre_c++;
	copy->map[y][x] = 'v';
	is_success(copy, x + 1, y);
	is_success(copy, x - 1, y);
	is_success(copy, x, y + 1);
	is_success(copy, x, y - 1);
}

void	fill_game(t_game	*game)
{
	int	width;
	int	height;

	width = 10;
	height = 10;
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * 32,
			game->map_height * 32, "so_long");
	game->wall_img = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/wall.xpm",
			&width, &height);
	game->player_img = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/player.xpm",
			&width, &height);
	game->open_exit_img = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/open_exit.xpm",
			&width, &height);
	game->close_exit_img = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/close_exit.xpm",
			&width, &height);
	game->collectible_img = load_image(game->mlx,
			"./Bonus/assets_bonus/textures_bonus/collectible.xpm", &width, &height);
	game->background_img = load_image(game->mlx,
			"./Bonus/assets_bonus/textures_bonus/background.xpm", &width, &height);
	game->frames[0] = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/enemy1.xpm",
			&width, &height);
	game->frames[1] = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/enemy2.xpm",
			&width, &height);
	game->frames[2] = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/enemy3.xpm",
			&width, &height);
	game->frames[3] = load_image(game->mlx, "./Bonus/assets_bonus/textures_bonus/enemy4.xpm",
			&width, &height);
	game->current_frame = 0;
	game->frame_counter = 0;
	game->total_moves = 0;
}

void update_enemy_animation (t_game *game)
{
	game->frame_counter++;
	if (game->frame_counter == 10)
	{
		game->current_frame = (game->current_frame + 1) % 4;
		game->frame_counter = 0;
	}
}

int game_loop(t_game *game)
{
	render_map(game);
	update_enemy_animation(game);
	return 0;
}

int	main(int argc, char	*argv[])
{
	t_game		game;
	t_copy		copy;

	if (argc == 2)
	{
		if (read_map(argv[1], &game))
		{
			game.mlx = mlx_init();
			if (!game.mlx)
				return (0);
			fill_game(&game);
			copy = copy_map(&game);
			is_success(&copy, game.player_x, game.player_y);
			if (game.total_coll == copy.countre_c && copy.countre_e == 1)
				{
					mlx_key_hook(game.mlx_win, key_handler, &game);
					printf("Total moves: %d\n", game.total_moves);
					mlx_loop_hook(game.mlx, game_loop, &game);
					mlx_loop(game.mlx);
				}
			else
				return (0);
		}
		else
			ft_putstr("Error\n======> 2 invalid map <======");
	}
}
