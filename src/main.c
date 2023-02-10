
#include "so_long.h"


char     **gnl_and_check(void)	
{
        int     a;
        char    *str;
        char    **tab;
        a = open("./src/map.ber", O_RDONLY);
        str = get_next_line(a);
        tab = ft_split(str, '\n');
        if (!checker_map(tab))
			printf("map ko");
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
	
	if (!initialisation(&data))
		return (0);
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