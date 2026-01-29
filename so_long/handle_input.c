/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:25:06 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:25:08 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map->map[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'C')
	{
		game->map->c_count--;
		game->map->map[y][x] = '0';
	}
	if (tile == 'E')
	{
		if (game->map->c_count != 0)
		{
			ft_printf("Devi raccogliere tutti i collectibles!\n");
			return (0);
		}
		ft_printf("Hai vinto in %d mosse!\n", game->moves + 1);
		free_game(game);
		exit(0);
	}
	return (1);
}

static void	apply_move(t_game *game, int x, int y)
{
	int	old_x;
	int	old_y;

	old_x = game->map->player_x;
	old_y = game->map->player_y;
	game->map->map[old_y][old_x] = '0';
	game->map->map[y][x] = 'P';
	game->map->player_x = x;
	game->map->player_y = y;
	game->moves++;
	ft_printf("Mosse: %d\n", game->moves);
	ft_printf("Nuova posizione player: x=%d, y=%d\n", x, y);
	render_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x + dx;
	new_y = game->map->player_y + dy;
	if (new_x < 0 || new_x >= game->map->width
		|| new_y < 0 || new_y >= game->map->height)
		return ;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	apply_move(game, new_x, new_y);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 'X' || keycode == KEY_ESC)
	{
		ft_printf("ESC pressed: exiting game.\n");
		free_game(game);
		exit(0);
	}
	else if (keycode == 'w' || keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == 's' || keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == 'a' || keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == 'd' || keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

int	handle_destroy(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
