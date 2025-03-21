/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:31:27 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/21 14:04:07 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_textures(t_mlx *mlx, t_game *game)
{
	int	width;
	int	height;
	int	bpp;
	int	size_line;
	int	endian;

	game->textures->no_text = mlx_xpm_file_to_image(mlx->mlx_pointer,
			game->textures->no_line, &width, &height);
	game->textures->no_data = mlx_get_data_addr(game->textures->no_text, &bpp,
			&size_line, &endian);
	game->textures->so_text = mlx_xpm_file_to_image(mlx->mlx_pointer,
			game->textures->so_line, &width, &height);
	game->textures->so_data = mlx_get_data_addr(game->textures->so_text, &bpp,
			&size_line, &endian);
	game->textures->ea_text = mlx_xpm_file_to_image(mlx->mlx_pointer,
			game->textures->ea_line, &width, &height);
	game->textures->ea_data = mlx_get_data_addr(game->textures->ea_text, &bpp,
			&size_line, &endian);
	game->textures->we_text = mlx_xpm_file_to_image(mlx->mlx_pointer,
			game->textures->we_line, &width, &height);
	game->textures->we_data = mlx_get_data_addr(game->textures->we_text, &bpp,
			&size_line, &endian);
}

void	start_game(t_mlx *mlx, t_game *game)
{
	mlx->mlx_pointer = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_pointer, S_WIDTH, S_HEIGHT, "cub3d");
	if (!mlx->window)
	{
		printf("Error: Window creation failed\n");
		exit(1);
	}
	put_textures(mlx, game);
	mlx->game = game;
	setup_hooks(mlx);
	mlx_loop(mlx->mlx_pointer);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_mlx		mlx;
	t_player	*player;

	init_game(&game);
	if (ac != 2)
	{
		err("Invalid ammount of arguments!");
		exit(0);
	}
	game.map = make_map(av[1], 0);
	if (!game.map)
	{
		printf("%sFailed to parse map.\n%s", RED, RESET);
		exit(0);
	}
	if (!good_input(&game))
		free_program(&game);
	init_key_states(&mlx.key_states);
	player = init_player(&game);
	mlx.player = player;
	start_game(&mlx, &game);
	propper_exit(&mlx);
	return (0);
}

int	good_input(t_game *game)
{
	t_textures	*temp;

	game->textures = malloc(sizeof(t_textures));
	init_textures_lines(game);
	temp = game->textures;
	if (!parse_textures_colors(&(game->map), game->textures))
		return (0);
	eliminate_spaces(game->textures);
	if (!all_paths_valid(game->textures))
		return (0);
	if (!only_one_player(game->map))
		return (err("More or less than one player"), 0);
	temp->ceil_col = rgb_to_hex(temp->ceil[0], temp->ceil[1], temp->ceil[2]);
	temp->fl_col = rgb_to_hex(temp->floor[0], temp->floor[1], temp->floor[2]);
	if (has_bad_char(game->map))
		return (err("Unrecognized charactr"), 0);
	get_map_dimensions(game->map, &game->width, &game->height);
	if (game->height > 100 || game->width > 200)
		return (err("Map too big"), 0);
	game->map_2d = convert_map(game);
	if (!game->map_2d)
		return (err("Failed to convert map"), 0);
	if (!is_surrounded(game))
		return (err("Map is not enclosed by walls"), 0);
	return (1);
}

t_map	*make_map(const char *file_path, int fd)
{
	char	*line;
	t_map	*head;
	t_map	*new_node;

	head = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (err("Couldn't open file"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		line = trim_newline(line);
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		new_node = create_node(line);
		if (!new_node)
			break ;
		append_node(&head, new_node);
		line = get_next_line(fd);
	}
	return (close(fd), head);
}
