/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:28:30 by educlos           #+#    #+#             */
/*   Updated: 2023/05/23 11:10:08 by educlos          ###   ########.fr       */
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
	char	*strnb;

	strnb = ft_itoa(data->nb_move);
	ft_putnbr_fd(data->nb_move, 1);
	write(1, "\n", 1);
	data->nb_move++;
	free(strnb);
}
