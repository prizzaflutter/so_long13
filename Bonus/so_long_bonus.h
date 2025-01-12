/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:27:34 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 13:27:51 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*wall_img;
	void	*player_img;
	void	*exit_img;
	void	*collectible_img;
	void	*background_img;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		total_coll;
}	t_game;
typedef struct s_copy
{
	char	**map;
	int		map_width;
	int		map_height;
	int		countre_c;
	int		countre_e;
}	t_copy;
char	*init_map(t_game *game, char *file_path, int fd);
int		fill_map(t_game *game, char *line, int fd, int	*y);
int		is_rectangular(char *line);
int		is_something_inside_map(char *line);
int		how_many(char *line, int is_last_call);
int		is_map_closed_by_walls(char *line, int is_last_line);
int		validate_map(char *next_line, char *line, int fd, t_game *game);
int		get_map_width(char *line);
int		get_map_heigth(char *file_path);
int		read_map(char *file_path, t_game *game);
int		render_map(t_game *game);
int		key_handler(int keycodes, t_game *game);
void	*load_image(void *mlx, char *file_path, int *width, int *height);
int		is_valid_move(t_game *game, int new_x, int new_y);
void	is_success(t_copy *copy, int x, int y);
char	*ft_strnstr(const char *haystack,
			const char *needle, size_t start, size_t len);
int		ft_putstr(char *str);
int		ft_putchar(char c);

#endif