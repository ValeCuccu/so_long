/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/15 16:42:32 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Helper per uscita con errore, chiude fd se aperto e stampa messaggio */
static void	error_exit_fd(int fd, const char *msg)
{
	if (fd >= 0)
		close(fd);
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

/* Controlla che il file ".ber" non sia una cartella */
void	open_file(char *argv, t_game *game)
{
	game->fd = open(argv, __O_DIRECTORY);
	if (game->fd != -1)
	{
		close(game->fd);
		error_exit_fd(-1, "Il percorso è una cartella, non un file");
	}
}

/* Controlla che il nome del file finisca con .ber */
int	has_ber_extension(const char *filename)
{
	size_t	len;

	if (!filename)
	{
		ft_printf("Mappa non presente\n");
		return (-1);
	}
	len = ft_strlen(filename);
	if (len < 5)
	{
		ft_printf("Problemi con nome mappa\n");
		return (-1);
	}
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r')
		return (1);
	return (0);
}

/* Inizializza una struttura mappa azzerata */
t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->map_copy = NULL;
	map->width = 0;
	map->height = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->mlx_ptr = NULL;
	return (map);
}

/* Legge e salva la mappa da file, gestisce fd e errori */
t_map	*load_map(const char *file)
{
	int		fd;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Errore: file (.ber)\n"), NULL);
	map = init_map();
	if (!map)
	{
		close(fd);
		ft_printf("Errore: malloc fallita per la mappa.\n");
		return (NULL);
	}
	if (!map_height(fd, map))
	{
		close(fd);
		free_map(map);
		return (NULL);
	}
	if (map->height > 0)
		map_width(map);
	close(fd);
	return (map);
}
