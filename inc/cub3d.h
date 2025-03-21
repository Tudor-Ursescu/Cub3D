/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:40:49 by tursescu          #+#    #+#             */
/*   Updated: 2024/12/26 13:31:26 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../dirs/libft/libft.h"
# include "../dirs/mlx/mlx.h"
# include "../inc/cub3dd.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define TILE_SIZE 720
# define MINI_TILE_SIZE 30
# define S_WIDTH 1600 // Define screen width
# define S_HEIGHT 900

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define MAX_KEY_CODE 65364
# define RED "\033[31m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"
# define GRID_CLOLUR 0x000000
# define MINI_P_TILE 10
# define PLAYER_COLOR 0xFF0000
# define PI 3.14159265
# define FOV 60

# define TEXTURE_NO "./inc/NO.xpm"
# define TEXTURE_SO "./inc/SO.xpm"
# define TEXTURE_WE "./inc/WE.xpm"
# define TEXTURE_EA "./inc/EA.xpm"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_textures
{
	char			*no_line;
	char			*so_line;
	char			*we_line;
	char			*ea_line;
	void			*no_text;
	void			*so_text;
	void			*we_text;
	void			*ea_text;
	char			*no_data;
	char			*so_data;
	char			*ea_data;
	char			*we_data;
	int				ceil[3];
	int				floor[3];
	int				ceil_col;
	int				fl_col;
}					t_textures;

typedef struct s_game
{
	int				seen_flag;
	float			wall_x;
	int				tex_x;
	int				tex_y;
	int				color;
	int				size_line;
	int				bpp;
	int				tex_y_offset;
	char			*text_data;
	char			*buff_data;
	void			*buffer;
	int				side;
	int				screen_line_height;
	int				draw_start;
	int				draw_end;
	size_t			map_x;
	size_t			map_y;
	size_t			p_x;
	size_t			p_y;
	float			stepx;
	float			stepy;
	float			first_ray_dist_x;
	float			first_ray_dist_y;
	float			delta_ray_dist_x;
	float			delta_ray_dist_y;
	float			ray_wall_length;
	bool			collision;
	char			wall_orientation;
	float			camera_x;
	float			direct_x;
	float			direct_y;
	float			raydirect_x;
	float			raydirect_y;
	float			plan_x;
	float			plan_y;
	float			curr_frame_time;
	float			prev_frame_time;
	t_map			*map;
	char			**map_2d;
	size_t			width;
	size_t			height;
	t_textures		*textures;
	t_mlx			*mlx;
	t_player		*player;
}					t_game;

void				mlx_put_pixel(t_game *game, int x, int y);

void				start_rays(t_mlx *mlx, t_game *game);
// INIT
void				init_game(t_game *game);
void				init_key_states(bool **key_states);
void				init_textures_lines(t_game *game);
int					get_player_y_position(t_game *game);
int					get_player_x_position(t_game *game);
// PARSING
int					is_valid_texture_path(const char *path);
char				*trim_newline(char *line);
t_map				*make_map(const char *file_path, int fd);
void				get_map_dimensions(t_map *head, size_t *width,
						size_t *height);
void				find_player_pos(t_map *head, size_t *x, size_t *y);
int					only_one_player(t_map *head);
int					players_in_row(const char *line);
int					is_surrounded(t_game *game);
void				flood_fill(t_map *head, size_t x, size_t y);
int					good_input(t_game *game);
int					parse_textures_colors(t_map **head, t_textures *textures);
int					parse_color(const char *line, int color[3]);
void				fill_from_zero(t_game *game);
void				complete_flood(t_game *game, size_t x, size_t y);
int					is_valid_adjacent(t_map *head, size_t x, size_t y);
int					has_bad_char(t_map *head);
int					is_wrong_char(char c);
void				initialize_seen_flags(int *arr);
int					check_missing_flags(int *seen_flag);
void				jump_lines(t_map **temp, t_map **current);
int					process_all_lines(t_map **current, int *seen_flag,
						t_textures *textures);
// UTILS
int					rgb_to_hex(int r, int g, int b);
int					is_player(char c);
int					is_space(char c);
t_map				*create_node(char *line);
void				err(char *str);
t_map				*copy_map(t_map *og);
void				append_node(t_map **head, t_map *new_node);
int					has_char(const char *str, char c);
char				get_char_at(t_map *head, size_t x, size_t y);
void				set_char_at(t_map *head, size_t x, size_t y, char c);
char				**convert_map(t_game *game);
void				eliminate_spaces(t_textures *textures);
void				rmv_space_in_str(char **str);
int					is_empty_line(char *line);
char				player_is_char(t_game *game);
char				*alloc_fill_row(char *line, size_t width);
void				game_over(t_mlx *mlx);
int					click_exit(t_mlx *mlx);
int					ft_strcmp(const char *s1, const char *s2);
int					all_paths_valid(t_textures *textures);
void				put_textures(t_mlx *mlx, t_game *game);
int					only_nb(char *line);
int					start_with_zero(char *line);
char				*trim_leading_ws(char *str);
// HOOKS
int					process_keys(t_mlx *mlx);
int					setup_hooks(t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);
int					key_release(int keycode, t_mlx *mlx);
int					game_loop(t_mlx *mlx);
// FREEING
void				free_list(t_map *head);
int					propper_exit(t_mlx *mlx);
void				free_2d_map(t_game *game);
void				free_textures(t_textures *textures);
void				free_matrix(char **matrix);
void				free_program(t_game *game);
void				destroy_all_img(t_mlx *mlx);
void				free_remaining_lines(t_map **current, t_map **head);
// DEBUG
void				print_map(t_map *head);
void				print_matrix(char **map, size_t height);
void				print_texture_path(t_game *game);
int					get_player_x_position(t_game *game);
int					get_player_y_position(t_game *game);

#endif
