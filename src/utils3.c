/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:41:30 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/21 14:04:38 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	game_over(t_mlx *mlx)
{
	ft_printf("%s╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n", RED);
	ft_printf("%s║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n", YELLOW);
	ft_printf("%s╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═%s", BLUE, RESET);
	ft_printf("\n");
	propper_exit(mlx);
}

int	click_exit(t_mlx *mlx)
{
	game_over(mlx);
	return (0);
}
