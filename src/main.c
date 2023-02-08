
#include "so_long.h"

char	*getting_file(char *buff, int fd)
{
	char	*readed;
	int		n;

	readed = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, readed, BUFFER_SIZE);
		if (n < 0)
		{
			free(readed);
			return (NULL);
		}
		readed[n] = '\0';
		buff = ft_strjoin(readed, buff);
		if (check(buff))
			n = 0;
	}
	free(readed);
	return (buff);
}

char	*getting_line(char *buff)
{
	char		*str;
	int			i;

	i = 0;
	if (buff[i] == 0)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	while (buff[i])
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*trimmed_buff(char *buff)
{
	char		*str;
	int			i;
	int			j;
	int			size;

	i = 0;
	j = 0;
	size = ft_strlen_classic(buff) - ft_strlen(buff);
	if (!size)
	{
		free(buff);
		return (NULL);
	}
	str = malloc(sizeof (char) * (size + 1));
	if (!str)
		return (NULL);
	i = ft_strlen(buff);
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = 0;
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*str;

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = getting_file(buff, fd);
	if (!buff)
		return (NULL);
	str = getting_line(buff);
	buff = trimmed_buff(buff);
	if (!str)
		free(buff);
	return (str);
}

char     **gnl_and_check(void)	
{
        int     a;
        char    *str;
        char    **tab;
        a = open("./src/map", O_RDONLY);
        str = get_next_line(a);
        tab = ft_split(str, '\n');
        /*if (!checker_map(tab))
            write(2, "MAP IS KO\n", 10);
        else
            write(2, "MAP IS OK\n", 10);
        */
        free(str);
        close(a);
        return (tab);
}

int	close_window(void)
{
	exit(1);
	return (0);
}
int free_all2(t_list *data)
{
	free(data->map);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->img2);
	mlx_destroy_image(data->mlx, data->trainer);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
int	handle_input(int keysym, t_list *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int key_press_hook(int keycode, t_list *data)
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
        exit (0);
	}
    return (0);
}


int main()
{
	t_list	data;
	
	initialisation(&data);
	exit_pos(&data);
	collect_total(&data);
	refresh(&data);
	mlx_hook(data.win, 17, (1L<<17), close_window, 0);
	mlx_hook(data.win, 2, 1L << 0, key_press_hook, &data);
	mlx_loop(data.mlx);
	free_all2(&data);
	return (0);
}

//faire fonction qui trouve x et y du player puis une fonction de recuperation de touche
// qui actualise la position du joueur 