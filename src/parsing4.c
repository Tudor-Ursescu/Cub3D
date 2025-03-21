/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:29:59 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/21 14:04:21 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	initialize_seen_flags(int *arr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		arr[i] = 0;
		i++;
	}
}

int	check_missing_flags(int *seen_flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (seen_flag[i] == 0)
		{
			err("Missing texture path, color or map");
			return (0);
		}
		i++;
	}
	return (1);
}

void	jump_lines(t_map **temp, t_map **current)
{
	*temp = *current;
	*current = (*current)->next;
	free((*temp)->line);
	free(*temp);
}

char	*trim_leading_ws(char *str)
{
	while (*str && is_space(*str))
		str++;
	return (str);
}
