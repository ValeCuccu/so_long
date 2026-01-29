/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:24:48 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:25:01 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	len;

	while (map->height > 0 && (map->map[map->height - 1][0] == '\n'
		|| map->map[map->height - 1][0] == '\0'))
		map->height--;
	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->map[i]);
		if (map->map[i][len - 1] == '\n')
			len--;
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	is_wall(t_map *map, int x, int y)
{
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
	{
		if (map->map[y][x] != '1')
			return (0);
	}
	return (1);
}

int	check_variables(t_map *map, char c, int x, int y)
{
	if (c == 'P')
	{
		map->p_count++;
		map->player_x = x;
		map->player_y = y;
		if (map->p_count > 1)
			return (ft_printf("Troppi player nella mappa\n"), 0);
	}
	else if (c == 'E')
		map->e_count++;
	else if (c == 'C')
		map->c_count++;
	else if (c != '0' && c != '1')
		return (ft_printf("Carattere non valido nella mappa\n"), 0);
	return (1);
}

int	check_elements(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (!is_wall(map, x, y))
				return (ft_printf("Pareti non chiuse correttamente\n"), 0);
			if (!check_variables(map, map->map[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (map->p_count != 1)
		return (ft_printf("Deve esserci esattamente un player\n"), 0);
	if (map->e_count < 1)
		return (ft_printf("Manca almeno una uscita\n"), 0);
	if ((map->e_count > 1) || (map->c_count < 1))
		return (ft_printf("Manca elementi\n"), 0);
	return (1);
}
