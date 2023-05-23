/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:02:12 by educlos           #+#    #+#             */
/*   Updated: 2023/05/16 12:03:15 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	refresh(t_list *data)
{
	int	j;
	int	k;

	j = 0;
	col_max(data);
	if (data->collect_total == data->collect_current)
		data->map[data->exit_col][data->exit_line] = 'E';
	while (j < data->map_col)
	{
		k = 0;
		while (k < ft_strlen(data->map[0]))
		{
			if (data->map[j][k] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img, k * 50,
					j * 50);
			else if (data->map[j][k] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img2, k
					* 50, j * 50);
			refresh2(j, k, data);
			k++;
		}
		j++;
	}
	compteur_pas(data);
}

void	refresh2(int j, int k, t_list *data)
{
	if (data->map[j][k] == 'P' && data->animation == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->trainer, k * 50, j
			* 50);
	else if (data->map[j][k] == 'P' && data->animation == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->trainer2, k * 50, j
			* 50);
	else if (data->map[j][k] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collectible, k * 50,
			j * 50);
	else if (data->map[j][k] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, k * 50, j
			* 50);
	else if (data->map[j][k] == 'Y')
		mlx_put_image_to_window(data->mlx, data->win, data->enemies, k * 50, j
			* 50);
}

/*			else if (data->map[j][k] == 'P' && data->animation == 0)
				mlx_put_image_to_window(data->mlx, data->win, data->trainer2, k
						* 50, j * 50);
			else if (data->map[j][k] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collectible,
						k * 50, j * 50);
			else if (data->map[j][k] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit, k
						* 50, j * 50);
			else if (data->map[j][k] == 'Y')
				mlx_put_image_to_window(data->mlx, data->win, data->enemies, k
						* 50, j * 50);*/
