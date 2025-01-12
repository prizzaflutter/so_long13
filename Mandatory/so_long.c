/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:28:03 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 16:40:57 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
void f()
{
	system("leaks so_long");
}
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
	if (copy->map[y][x] == '1' || copy->map[y][x] == 'v'
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
	game->wall_img = load_image(game->mlx,
			"./Mandatory/assets/textures/wall.xpm", &width, &height);
	game->player_img = load_image(game->mlx,
			"./Mandatory/assets/textures/player.xpm", &width, &height);
	game->exit_img = load_image(game->mlx,
			"./Mandatory/assets/textures/exit.xpm", &width, &height);
	game->collectible_img = load_image(game->mlx,
			"./Mandatory/assets/textures/collectible.xpm", &width, &height);
	game->background_img = load_image(game->mlx,
			"./Mandatory/assets/textures/background.xpm", &width, &height);
}

int	main(int argc, char	*argv[])
{
	t_game		game;
	t_copy		copy;

	if (argc == 2)
	{
		atexit(f);
		if (read_map(argv[1], &game))
		{
			game.mlx = mlx_init();
			if (!game.mlx)
				return (0);
			fill_game(&game);
			copy = copy_map(&game);
			is_success(&copy, game.player_x, game.player_y);
			if (game.total_coll == copy.countre_c && copy.countre_e == 1)
				render_map(&game);
			else
				return (0);
			mlx_key_hook(game.mlx_win, key_handler, &game);
			mlx_loop(game.mlx);
		}
		else
			ft_putstr("Error\n======> 2 invalid map <======");
	}
}
