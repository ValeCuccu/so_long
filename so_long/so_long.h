/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:56:47 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 19:13:14 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_MAP_HEIGHT 1024
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./Libft/libft.h"
# include "mlx/mlx.h"

# define TILE_SIZE 64

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		width;
	int		height;
	int		p_count;
	int		player_x;
	int		player_y;
	int		e_count;
	int		exit_x;
	int		exit_y;
	int		c_count;
	void	*mlx_ptr;
	int		check_exit;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		moves;
	int		fd;
}	t_game;

t_map		*load_map(const char *file);
char		**copy_map(t_map *map);
int			has_ber_extension(const char *filename);
int			check_rectangular(t_map *map);
int			check_elements(t_map *map);
int			check_path_valid(t_map *map);
int			init_game(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			handle_destroy(t_game *game);
int			map_height(int fd, t_map *map);
int			validate_map(t_game *game, char *file);
void		map_width(t_map *map);
void		free_map(t_map *map);
void		render_map(t_game *game);
void		free_game(t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		open_file(char *argv, t_game *game);

#endif
