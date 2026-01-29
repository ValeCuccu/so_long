/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:24:53 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 19:17:09 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y, t_map *m)
{
	if (map[y][x] == 'E')
		m->check_exit = 1;
	if (map[y][x] == '1' || map[y][x] == 'F' ||
	map[y][x] == 'E' || map[y][x] == '\n')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, m);
	flood_fill(map, x - 1, y, m);
	flood_fill(map, x, y + 1, m);
	flood_fill(map, x, y - 1, m);
}

int	check_path_valid(t_map *map)
{
	int	y;
	int	x;

	flood_fill(map->map_copy, map->player_x, map->player_y, map);
	if (map->check_exit == 0)
		return (0);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map_copy[y][x] && map->map_copy[y][x] != '\n')
		{
			if (map->map_copy[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
