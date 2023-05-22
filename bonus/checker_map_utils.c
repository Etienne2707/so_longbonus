/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:28:58 by educlos           #+#    #+#             */
/*   Updated: 2023/05/22 11:38:09 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_arg(int argc, char *str)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		return ;
	}
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e' && str[i
				+ 3] == 'r' && str[i + 4] == '\0')
			return ;
		i++;
	}
	write(2, "Invalid map type\n", 12);
	exit(0);
}

void	check_file(char *map)
{
	char	buff[42];
	int		n;
	int		a;

	a = open(map, O_RDONLY);
	n = read(a, buff, 42);
	if (n < 0)
		return ;
	if (n == 0)
	{
		write(2, "Invalid map\n", 12);
		close(a);
		exit(0);
	}
	n = 0;
	while (buff[n] == '1')
		n++;
	if ((buff[n] != '\n' && buff[n] != '\0') || n == 0)
	{
		write(2, "Invalid map\n", 12);
		close(a);
		exit(0);
	}
	close(a);
	return ;
}

void	error(char *str, char **tab)
{
	int	i;

	i = 0;
	free(str);
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	write(2, "Map invalide", 12);
}

int	check_c(char **tab)
{
	int	i;
	int	y;
	int	c;

	c = 0;
	i = 0;
	while (tab[i] != 0)
	{
		y = 0;
		while (tab[i][y] != '\0')
		{
			if (tab[i][y] == 'C')
				c++;
			y++;
		}
		i++;
	}
	if (c < 1)
		return (0);
	else
		return (1);
}
