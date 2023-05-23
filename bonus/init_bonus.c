/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:22:35 by educlos           #+#    #+#             */
/*   Updated: 2023/05/23 14:45:28 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	one_p_e(char **tab, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

int	free_all2(t_list *data)
{
	free_all(data->map, test(data->map));
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->img2);
	mlx_destroy_image(data->mlx, data->trainer);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->trainer2);
	mlx_destroy_image(data->mlx, data->enemies);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	initialisation(int argc, char **argv, t_list *data)
{
	int	i;

	data->collect_current = 0;
	data->nb_move = 0;
	data->animation = 0;
	data->map = gnl_and_check(argc, argv);
	if (data->map == NULL)
		return (0);
	if (path_check(argc, argv, data->map) == NULL)
		return (0);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	col_max(data);
	data->win = mlx_new_window(data->mlx, ft_strlen(data->map[0]) * 50,
			(data->map_col) * 50, "so_long");
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/1.xpm", &i, &i);
	data->img2 = mlx_xpm_file_to_image(data->mlx, "./img/0.xpm", &i, &i);
	data->trainer = mlx_xpm_file_to_image(data->mlx, "./img/p.xpm", &i, &i);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./img/c.xpm", &i, &i);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./img/e.xpm", &i, &i);
	data->trainer2 = mlx_xpm_file_to_image(data->mlx, "./img/p_l2.xpm", &i, &i);
	data->enemies = mlx_xpm_file_to_image(data->mlx, "./img/x.xpm", &i, &i);
	return (1);
}
