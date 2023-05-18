/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:03:45 by educlos           #+#    #+#             */
/*   Updated: 2023/05/18 19:38:55 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**gnl_and_check(int argc, char **argv)
{
	int		a;
	char	*str;
	char	**tab;

	check_map_arg(argc, argv[1]);
	check_file(argv[1]);
	a = open(argv[1], O_RDONLY);
	str = get_next_line(a);
	if (!str)
	{
		printf("Fichier vide");
		return (NULL);
	}
	check_empty_line(str);
	tab = ft_split(str, '\n');
	if (!checker_map(tab))
	{
		Error(str, tab);
		return (NULL);
	}
	else
		printf("map ok");
	free(str);
	close(a);
	return (tab);
}

int	close_window(void)
{
	exit(1);
	return (0);
}

int	handle_input(int keysym, t_list *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	key_press_hook(int keycode, t_list *data)
{
	if (keycode == 119)
		event(keycode, data);
	if (keycode == 97)
		event(keycode, data);
	if (keycode == 115)
		event(keycode, data);
	if (keycode == 100)
		event(keycode, data);
	if (keycode == 65307)
	{
		free_all2(data);
		exit(0);
	}
	return (0);
}

int	main(int argc , char **argv)
{
	t_list	data;

	if (!initialisation(argc, argv, &data))
		return (0);
	exit_pos(&data);
	collect_total(&data);
	refresh(&data);
	mlx_hook(data.win, 17, (1L << 19), close_window, 0);
	mlx_hook(data.win, 2, 1L << 0, &key_press_hook, &data);
	mlx_loop(data.mlx);
	free_all2(&data);
	return (0);
}
