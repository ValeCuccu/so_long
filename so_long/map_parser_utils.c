/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:25:30 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:25:32 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(int fd, t_map *map)
{
	char	*line;
	int		i;

	map->map = malloc(sizeof(char *) * (MAX_MAP_HEIGHT + 1));
	if (!map->map)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map[i++] = line;
		if (i >= MAX_MAP_HEIGHT)
			break ;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	map->height = i;
	return (1);
}

void	map_width(t_map *map)
{
	int	len;

	len = ft_strlen(map->map[0]);
	if (map->map[0][len - 1] == '\n')
		len--;
	map->width = len;
}
