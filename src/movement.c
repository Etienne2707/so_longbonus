/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:18:27 by educlos           #+#    #+#             */
/*   Updated: 2023/05/15 14:23:50 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	w_mov(t_list *data, int x, int y)
{
	if (data->map[x - 1][y] == '1')
		return (0);
	if ((data->map[x - 1][y] == 'E' && data->collect_total == data->collect_current)
	|| data->map[x - 1][y] == 'Y')
		free_all2 (data);
	if (data->map[x - 1][y] == 'C')
		data->collect_current++;
	data->map[x - 1][y] = data->map[x][y];
	data->map[x][y] = '0';
	return (1);
}
int	a_mov(t_list *data, int x, int y)
{
	if (data->map[x][y - 1] == '1')
		return (0);
	if ((data->map[x][y - 1] == 'E' && data->collect_total == data->collect_current)
	|| data->map[x][y - 1] == 'Y')
		free_all2(data);
	if (data->map[x][y - 1] == 'C')
		data->collect_current++;
	data->map[x][y - 1] = data->map[x][y];
	data->map[x][y] = '0';
	data->animation = 0;
	return (1);
}

int	s_mov(t_list *data, int x, int y)
{
	if (data->map[x + 1][y] == '1')
		return (0);
	if ((data->map[x + 1][y] == 'E' && data->collect_total == data->collect_current) 
	|| data->map[x + 1][y] == 'Y')
		free_all2(data);
	if (data->map[x + 1][y] == 'C')
		data->collect_current++;
	data->map[x + 1][y] = data->map[x][y];
	data->map[x][y] = '0';
	return (1);
}

int	d_mov(t_list *data, int x, int y)
{
	if (data->map[x][y + 1] == '1')
		return (0);
	if ((data->map[x][y + 1] == 'E' && data->collect_total == data->collect_current) 
	|| data->map[x][y + 1] == 'Y')
		free_all2(data);
	if (data->map[x][y + 1] == 'C')
		data->collect_current++;
	data->map[x][y + 1] = data->map[x][y];
	data->map[x][y] = '0';
	data->animation = 1;
	return (1);
}
