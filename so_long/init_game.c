/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:25:13 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 19:16:05 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->map->check_exit = 0;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (0);
	mlx_hook(game->win_ptr, 17, 0, handle_destroy, game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/wall.xpm",
			&(int){0}, &(int){0});
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/floor.xpm",
			&(int){0}, &(int){0});
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/player.xpm",
			&(int){0}, &(int){0});
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/collectible.xpm", &(int){0}, &(int){0});
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/exit.xpm",
			&(int){0}, &(int){0});
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collectible || !game->img_exit)
		return (0);
	game->moves = 0;
	return (1);
}

static void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_player, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile = game->map->map[y][x];
			render_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
}
