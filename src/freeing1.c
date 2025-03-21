/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:23:00 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/21 14:03:42 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_resources(t_mlx *mlx)
{
	destroy_all_img(mlx);
	if (mlx->window)
	{
		mlx_clear_window(mlx->mlx_pointer, mlx->window);
		mlx_destroy_window(mlx->mlx_pointer, mlx->window);
	}
	if (mlx->mlx_pointer)
	{
		mlx_destroy_display(mlx->mlx_pointer);
		mlx_loop_end(mlx->mlx_pointer);
		free(mlx->mlx_pointer);
		mlx->mlx_pointer = NULL;
	}
	if (mlx->key_states)
	{
		free(mlx->key_states);
		mlx->key_states = NULL;
	}
	if (mlx->player)
		free(mlx->player);
}

void	free_program(t_game *game)
{
	if (game->map)
	{
		free_list(game->map);
		game->map = NULL;
	}
	if (game->map_2d)
	{
		free_2d_map(game);
		game->map_2d = NULL;
	}
	if (game->textures)
	{
		free_textures(game->textures);
		game->textures = NULL;
	}
	exit(0);
}

int	propper_exit(t_mlx *mlx)
{
	free_resources(mlx);
	free_program(mlx->game);
	return (0);
}

void	free_list(t_map *head)
{
	t_map	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->line);
		free(temp);
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
