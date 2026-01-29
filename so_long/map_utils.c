/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:25:36 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:29:49 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->map)
	{
		while (map->map[i])
			free (map->map[i++]);
		free (map->map);
	}
	if (map->map_copy)
	{
		i = 0;
		while (map->map_copy[i])
			free(map->map_copy[i++]);
		free(map->map_copy);
	}
	free (map);
}

char	**copy_map(t_map *map)
{
	char	**new_map;
	int		y;

	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (!new_map)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		new_map[y] = ft_strdup(map->map[y]);
		if (!new_map[y])
		{
			while (--y >= 0)
				free(new_map[y]);
			free(new_map);
			return (NULL);
		}
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->fd > 0)
		close(game->fd);
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx_ptr, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

/* int	validate_map(t_game *game, char *file)
{
	open_file(file, game);
	game->map = load_map(file);
	if (!game->map || game->map->height == 0 || game->map->width == 0)
		return (ft_printf("Error\nMappa vuota o non valida.\n"), 0);
	if (game->map->width < 3 || game->map->height < 3)
		return (ft_printf("Error\nLa mappa è troppo piccola.\n"), 0);
	if (!check_rectangular(game->map))
		return (ft_printf("Error\nLa mappa NON è rettangolare.\n"), 0);
	if (!check_elements(game->map))
		return (ft_printf("Error\nelementi o pareti o player > 1\n"), 0);
	game->map->map_copy = copy_map(game->map);
	if (!game->map->map_copy)
		return (ft_printf("Error\nImpossibile copiare la mappa.\n"), 0);
	if (!check_path_valid(game->map))
	{
		ft_printf("Error\nIl percorso non è valido: ");
		ft_printf("collectibles o uscita irraggiungibili.\n");
		return (0);
	}
	return (1);
} */
