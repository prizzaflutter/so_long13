/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_heigth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:19:26 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 13:22:33 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_heigth(char *file_path)
{
	int		fd;
	char	*line;
	int		number_of_line;
	char	*next_line;

	number_of_line = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		next_line = get_next_line(fd);
		number_of_line++;
		free(line);
		line = next_line;
	}
	close(fd);
	return (number_of_line);
}
