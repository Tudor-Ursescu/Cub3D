# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 10:51:39 by tursescu          #+#    #+#              #
#    Updated: 2024/12/26 11:33:17 by tursescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = src/parsing_utils1.c src/utils1.c  src/parsing1.c src/parsing2.c src/freeing1.c\
		src/debug.c src/utils2.c src/freeing2.c src/init.c src/parsing_utils2.c src/hooks.c src/init_player.c \
		src/render.c src/utils3.c src/utils4.c src/utils5.c src/main.c src/render2.c src/parsing3.c \
		src/parsing4.c 
CC = cc
RM = rm -f
LIBFT_DIR = dirs/libft
MLX_DIR = dirs/mlx
CFLAGS = -g -Wall -Wextra -Werror -Iinclude/mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
OBJ = $(SRC:.c=.o)
NAME = cub3D
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIBS) -o $(NAME)
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBS)
re: fclean all

.PHONY: all libft clean fclean re