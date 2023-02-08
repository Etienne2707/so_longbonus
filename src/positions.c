/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:51:15 by tbelleng          #+#    #+#             */
/*   Updated: 2023/02/08 17:01:43 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	collect_total(t_list *data)
{
	int     x;
	int     y;
	
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

void     player_pos(t_list *data)
{
	int     x;
	int     y;
	
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

void     exit_pos(t_list *data)
{
{
	int     x;
	int     y;
	
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