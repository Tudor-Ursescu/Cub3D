/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:14:09 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/21 14:03:50 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_textures(t_textures *textures)
{
	if (textures->no_line)
		free(textures->no_line);
	if (textures->so_line)
		free(textures->so_line);
	if (textures->ea_line)
		free(textures->ea_line);
	if (textures->we_line)
		free(textures->we_line);
	free(textures);
}

void	free_2d_map(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->map_2d)
		return ;
	while (i < game->height)
	{
		free(game->map_2d[i]);
		i++;
	}
	free(game->map_2d);
}

void	destroy_all_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->no_text);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->so_text);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->ea_text);
	mlx_destroy_image(mlx->mlx_pointer, mlx->game->textures->we_text);
}

void	free_remaining_lines(t_map **current, t_map **head)
{
	t_map	*temp;

	*head = NULL;
	while (*current)
	{
		temp = *current;
		*current = (*current)->next;
		free(temp->line);
		free(temp);
	}
}
