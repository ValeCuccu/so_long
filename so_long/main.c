/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:25:23 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:32:36 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_args_and_file(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (ft_printf("Error\nUso: %s <mappa.ber>\n", argv[0]), 1);
	if (!has_ber_extension(argv[1]))
		return (ft_printf("Error\nfile non .ber\n"), 1);
	open_file(argv[1], game);
	game->map = load_map(argv[1]);
	if (!game->map)
		return (ft_printf("Error\nImpossibile caricare la mappa.\n"), 1);
	if (!game->map->map || !game->map->map[0]
		|| game->map->map[0][0] == '\0')
		return (free_map(game->map), close(game->fd),
			ft_printf("Error\nLa mappa è vuota.\n"), 1);
	return (0);
}

static int	validate_map_and_game(t_game *game)
{
	if (game->map->width < 3 || game->map->height < 3)
		return (free_map(game->map), close(game->fd),
			ft_printf("Error\nLa mappa è troppo piccola.\n"), 1);
	if (!check_rectangular(game->map))
		return (free_map(game->map), close(game->fd),
			ft_printf("Error\nLa mappa NON è rettangolare.\n"), 1);
	if (!check_elements(game->map))
		return (free_map(game->map), close(game->fd),
			ft_printf("Error\nLa mappa ha elementi invalidi.\n"), 1);
	game->map->map_copy = copy_map(game->map);
	if (!game->map->map_copy)
		return (free_map(game->map), close(game->fd),
			ft_printf("Error\nErrore durante la copia della mappa.\n"), 1);
	if (!check_path_valid(game->map))
		return (free_map(game->map), close(game->fd),
			ft_printf("Error\nPercorso non valido.\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (validate_args_and_file(argc, argv, &game))
		return (1);
	if (validate_map_and_game(&game))
		return (1);
	if (!init_game(&game))
		return (free_map(game.map), close(game.fd),
			ft_printf("Error\nErrore nel gioco.\n"), 1);
	render_map(&game);
	mlx_key_hook(game.win_ptr, handle_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, handle_destroy, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
