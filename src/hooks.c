/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:28:46 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/21 14:03:53 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_player(t_mlx *mlx, float dx, float dy)
{
	float	new_x;
	float	new_y;

	new_x = mlx->player->player_x + dx * cos(mlx->player->player_angle) - dy
		* sin(mlx->player->player_angle);
	new_y = mlx->player->player_y + dx * sin(mlx->player->player_angle) + dy
		* cos(mlx->player->player_angle);
	if (new_x >= 0 && new_x < mlx->game->width && new_y >= 0
		&& new_y < mlx->game->height
		&& mlx->game->map_2d[(int)new_y][(int)new_x] != '1')
	{
		mlx->player->player_x = new_x;
		mlx->player->player_y = new_y;
		mlx->player = mlx->player;
	}
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode >= 0 && keycode < MAX_KEY_CODE)
		mlx->key_states[keycode] = true;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode >= 0 && keycode < MAX_KEY_CODE)
		mlx->key_states[keycode] = false;
	return (0);
}

int	process_keys(t_mlx *mlx)
{
	if (mlx->key_states[ESC_KEY])
		game_over(mlx);
	if (mlx->key_states[A_KEY])
		move_player(mlx, 0, -0.1 / 2);
	if (mlx->key_states[D_KEY])
		move_player(mlx, 0, 0.1 / 2);
	if (mlx->key_states[S_KEY])
		move_player(mlx, -0.1 / 2, 0);
	if (mlx->key_states[W_KEY])
		move_player(mlx, 0.1 / 2, 0);
	if (mlx->key_states[LEFT_KEY])
	{
		mlx->player->player_angle -= 0.1 / 2;
		if (mlx->player->player_angle < 0)
			mlx->player->player_angle += 2 * PI;
	}
	if (mlx->key_states[RIGHT_KEY])
	{
		mlx->player->player_angle += 0.1 / 2;
		if (mlx->player->player_angle >= 2 * PI)
			mlx->player->player_angle -= 2 * PI;
	}
	start_rays(mlx, mlx->game);
	return (0);
}

int	setup_hooks(t_mlx *mlx)
{
	if (!mlx || !mlx->window)
	{
		printf("Error: mlx or window not initialized\n");
		return (1);
	}
	mlx_hook(mlx->window, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->window, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->window, 17, 0L, click_exit, mlx);
	mlx_loop_hook(mlx->mlx_pointer, process_keys, mlx);
	return (0);
}
