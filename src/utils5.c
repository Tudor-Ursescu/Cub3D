/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:15:23 by tlupu             #+#    #+#             */
/*   Updated: 2025/03/21 14:04:44 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	mlx_put_pixel(t_game *game, int x, int y)
{
	int	pixel_index;

	pixel_index = (y * game->size_line) + (x * (game->bpp / 8));
	game->buff_data[pixel_index] = game->color & 0xFF;
	game->buff_data[pixel_index + 1] = (game->color >> 8) & 0xFF;
	game->buff_data[pixel_index + 2] = (game->color >> 16) & 0xFF;
}

void	mlx_put_pixel_fc(t_game *game, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = (y * game->size_line) + (x * (game->bpp / 8));
	game->buff_data[pixel_index] = color & 0xFF;
	game->buff_data[pixel_index + 1] = (color >> 8) & 0xFF;
	game->buff_data[pixel_index + 2] = (color >> 16) & 0xFF;
}
