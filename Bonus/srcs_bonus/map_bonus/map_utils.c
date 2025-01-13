/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:02:16 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/13 09:56:31 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	is_rectangular(char *line)
{
	static int	first_row_lenght;
	static int	is_get_first_line;

	if (!line)
		return (0);
	if (is_get_first_line == 0)
	{
		first_row_lenght = get_map_width(line);
		is_get_first_line = 1;
	}
	else if (first_row_lenght != get_map_width(line))
	{
		ft_putstr("map is not rectangular");
		return (0);
	}
	return (1);
}

int	is_map_closed_by_walls(char *line, int is_last_line)
{
	int	i;
	int	len;

	i = 0;
	len = get_map_width(line);
	if (!is_last_line)
	{
		if (line[0] != '1' || line[len - 1] != '1')
			return (0);
	}
	else
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int	how_many(char *line, int is_last_call)
{
	int			i;
	static int	how_many_e;
	static int	how_many_p;
	static int	how_many_c;

	i = 0;
	if (is_last_call)
	{
		if (how_many_e == 1 && how_many_p == 1 && how_many_c >= 1)
			return (how_many_c);
		else
			return (0);
	}
	while (line[i])
	{
		if (line[i] == 'E')
			how_many_e++;
		else if (line[i] == 'P')
			how_many_p++;
		else if (line[i] == 'C')
			how_many_c++;
		i++;
	}
	return (1);
}

int	is_something_inside_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'E' || line[i] == 'C' || line[i] == 'N'
			|| line[i] == 'P' || line[i] == '0' || line[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	read_map(char *path, t_game *game)
{
	char	*line;
	int		y;
	char	*next_line;
	int		fd;

	y = 0;
	if (ft_strnstr(path, ".ber", ft_strlen(path) - 4, ft_strlen(path)) == NULL)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = init_map(game, path, fd);
	while (line)
	{
		next_line = get_next_line(fd);
		if (!fill_map(game, line, fd, &y)
			|| !validate_map(next_line, line, fd, game))
			return (free(line), free(next_line), 0);
		free(line);
		line = next_line;
		y++;
	}
	game->map[y] = NULL;
	close(fd);
	return (1);
}
