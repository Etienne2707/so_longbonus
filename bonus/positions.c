/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:51:15 by tbelleng          #+#    #+#             */
/*   Updated: 2023/05/16 15:23:43 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	col_max(t_list *data)
{
	int	x;
	int	y;

	x = 0;
	data->map_col = 0;
	while (data->map[x] != 0)
	{
		y = 0;
		while (data->map[x][y] != '\0')
			y++;
		x++;
	}
	data->map_col = x;
}

void	collect_total(t_list *data)
{
	int	x;
	int	y;

	x = 0;
	data->collect_total = 0;
	while (data->map[x] != 0)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'C')
				data->collect_total++;
			y++;
		}
		x++;
	}
}

void	player_pos(t_list *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x] != 0)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'P')
			{
				data->player_col = x;
				data->player_line = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	exit_pos(t_list *data)
{
	int	x;
	int	y;

	{
		x = 0;
		while (data->map[x] != 0)
		{
			y = 0;
			while (data->map[x][y] != '\0')
			{
				if (data->map[x][y] == 'E')
				{
					data->map[x][y] = '0';
					data->exit_line = y;
					data->exit_col = x;
				}
				y++;
			}
			x++;
		}
	}
}

int	test(char **str)
{
	int	x;
	int	y;

	x = 0;
	while (str[x] != 0)
	{
		y = 0;
		while (str[x][y] != '\0')
			y++;
		x++;
	}
	return (x);
}
