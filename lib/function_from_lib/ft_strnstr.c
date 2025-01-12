/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:17:00 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/12 14:42:46 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Mandatory/so_long.h"

char	*ft_strnstr(const char *haystack,
	const char *needle, size_t start, size_t len)
{
	size_t	j;
	char	*str;

	str = (char *)haystack;
	if (needle[0] == '\0' || needle == NULL)
		return (str);
	while (str[start] != '\0' && start < len)
	{
		j = 0;
		while (needle[j] != '\0'
			&& (start + j) < len && str[start + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (&str[start]);
		start++;
	}
	return (NULL);
}
