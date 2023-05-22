/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:28:30 by educlos           #+#    #+#             */
/*   Updated: 2023/05/16 15:28:33 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	str = malloc(sizeof(char) * i + k + 1);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = 0;
	return (str);
}

void	compteur_pas(t_list *data)
{
	int		x;
	int		y;
	char	*str;
	char	*strnb;

	x = 50;
	y = 50;
	str = "nombre de d'action :";
	strnb = ft_itoa(data->nb_move);
	str = ft_join(str, strnb);
	mlx_string_put(data->mlx, data->win, x, y, 1, str);
	data->nb_move++;
	free(str);
	free(strnb);
}
