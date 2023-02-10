#include "so_long.h"

int    initialisation(t_list *data)
{
    int i;

    data->collect_current = 0;
	data->nb_move = 0; 
	data->animation = 0;
	data->map = gnl_and_check();
	if (path_check(data->map) == NULL)
        return 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return 0;
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/1.xpm", &i, &i);
	data->img2 = mlx_xpm_file_to_image(data->mlx, "./img/0.xpm", &i, &i);
	data->trainer = mlx_xpm_file_to_image(data->mlx, "./img/p.xpm", &i, &i);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./img/c.xpm", &i, &i);
    data->exit = mlx_xpm_file_to_image(data->mlx, "./img/e.xpm", &i, &i);
	data->trainer2 = mlx_xpm_file_to_image(data->mlx, "./img/p_l2.xpm", &i, &i);
	data->enemies = mlx_xpm_file_to_image(data->mlx, "./img/x.xpm", &i, &i);
	return (1);
}