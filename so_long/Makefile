# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpastac <anpastac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:58:41 by vacuccu           #+#    #+#              #
#    Updated: 2025/06/26 16:40:31 by anpastac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -ILibft #-Imlx

SRCS = main.c load_map.c map_utils.c check_map.c flood_fill.c init_game.c handle_input.c map_parser_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT_A = $(LIBFT_DIR)/libft.a

#MLX_DIR = mlx
#MLX_A = $(MLX_DIR)/libmlx.a

.PHONY: all clean fclean re libft #mlx

all: $(NAME)

# Compila il programma solo se OBJS, libft.a e libmlx.a sono aggiornati
$(NAME): $(OBJS) $(LIBFT_A) #$(MLX_A)#
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) #$(MLX_A) -lXext -lX11 -lm -lz -o $(NAME)#

# Regola generica per .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Libft
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Mlx
#$(MLX_A):
#	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
#	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
