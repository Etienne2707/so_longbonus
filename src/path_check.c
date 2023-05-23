/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:33 by educlos           #+#    #+#             */
/*   Updated: 2023/05/23 15:50:12 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	roadmap(char **str)
{
	int	x;
	int	y;

	x = 1;
	while (str[x] != 0)
	{
		y = 1;
		while (str[x][y] != '\0')
		{
			if (str[x][y] == 'C' || str[x][y] == 'E')
			{
				free_all(str, test(str));
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_croix_axe_x(char **str, int x, int y)
{
	int	a;

	a = x;
	while (str[++x][y] == '0' || str[x][y] == 'C' || str[x][y] == 'E')
		str[x][y] = 'x';
	x = a;
	while (str[--x][y] == '0' || str[x][y] == 'C' || str[x][y] == 'E')
		str[x][y] = 'x';
}

void	ft_croix(char **str, int x, int y)
{
	int	a;
	int	b;

	a = x;
	b = y;
	while (str[x][++y] == '0' || str[x][y] == 'C' || str[x][y] == 'E')
		str[x][y] = 'x';
	y = b;
	while (str[x][--y] == '0' || str[x][y] == 'C' || str[x][y] == 'E')
		str[x][y] = 'x';
	ft_croix_axe_x(str, a, b);
}

void	start(char **str)
{
	int	y;
	int	x;

	y = 0;
	x = 1;
	x = 1;
	while (str[x] != 0)
	{
		y = 1;
		while (str[x][y] != '\0')
		{
			if (str[x][y] == 'x')
				ft_croix(str, x, y);
			y++;
		}
		x++;
	}
}

char	**path_check(int argc, char **argv, char **map)
{
	int		x;
	int		y;
	char	**str;

	x = 0;
	str = gnl_and_check(argc, argv);
	while (str[x++] != 0)
	{
		y = -1;
		while (str[x][++y] != '\0')
		{
			if (str[x][y] == 'P')
				break ;
		}
		if (str[x][y] == 'P')
			break ;
	}
	str[x][y] = 'x';
	ft_croix(str, x, y);
	start(str);
	start(str);
	if (roadmap(str) == 0)
		return (NULL);
	free_all(str, test(str));
	return (map);
}
