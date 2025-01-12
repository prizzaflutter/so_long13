/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:37:39 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 13:24:07 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*load_image(void *mlx, char *file_path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, file_path, width, height);
	if (!img)
		return (NULL);
	return (img);
}
