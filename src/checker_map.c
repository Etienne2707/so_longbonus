
#include "so_long.h"

//prendre le fichier complet et mettre dans une string
//split sur la string
//checker que chqaue ligne a la meme lenght et qu elle finisse toute par un \n
//checker que chaque ligne commence et finisse par 1
//checker que la premier et derniere ligne est full 1
//checker les elements

int	checker_map(char **tab)
{
	if (!check_char(tab))
		return (0);
	if (!check_length(tab))
		return (0);
	if (!check_startend(tab))
		return (0);
	if (!check_full_one(tab))
		return (0);
	if (!one_p_e(tab, 'P'))
		return (0);
	if (!one_p_e(tab, 'E'))
		return (0);
	free(tab);
	return (1);
}

int     check_char(char **tab)
{
	int     i;
	int     j;
	
	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != 'E' && tab[i][j] != 'P' && tab[i][j] != 'C'
					&& tab[i][j] != '0' && tab[i][j]  != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int     check_length(char **tab)
{
	int     i;
	int     len;
	int     current_len;
	
	i = 0;
	len = ft_strlen(tab[i]);
	current_len = 0;
	while (tab[i] != 0)
	{
		current_len = ft_strlen(tab[i]);
		if (current_len != len)
			return (0);
		i++;
	}
	return (1);
}

int     check_startend(char **tab)
{
	int     i;
	int     len;
	
	i = 0;
	len = 0;
	while (tab[i] != 0)
	{
		len = ft_strlen(tab[i]);
		if (tab[i][0] != '1' && tab[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int     line_count(char **tab)
{
	int     i;
	
	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int     check_full_one(char **tab)
{
	int     line_nb;
	int     k;
	
	line_nb = line_count(tab);
	while (tab[0][0] != '\0')
	{
		k = 0;
		while (tab[0][k] != '\0')
		{
			if (tab[0][k] != '1')
				return (0);
			k++;
		}
		k = 0;
		while (tab[line_nb - 1][k] != '\0')
		{
			if (tab[line_nb - 1][k] != '1')
				return (0);
			k++;
		}
		break;
	}
	return (1);
}

int     one_p_e(char **tab, char c)
{
	int     i;
	int     j;
	int     count;
	
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