#include "so_long.h"

void    refresh(t_list *data)
{
    int j;
    int k;

    j = 0;
    k = 0;
    if (data->collect_total == data->collect_current)
        data->map[data->exit_col][data->exit_line] = 'E';
    while (j < 5)
	{
		k = 0;
		while (k < ft_strlen(data->map[0]))
		{
			if (data->map[j][k] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->img, k*50, j*50);
            else if (data->map[j][k] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->img2, k*50, j*50);
            else if (data->map[j][k] == 'P' && data->animation == 1)
                mlx_put_image_to_window(data->mlx, data->win, data->trainer, k*50, j*50);
            else if (data->map[j][k] == 'P' && data->animation == 0)
                mlx_put_image_to_window(data->mlx, data->win, data->trainer2, k*50, j*50);
            else if (data->map[j][k] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->collectible, k*50, j*50);
            else if (data->map[j][k] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, k*50, j*50);
            else if (data->map[j][k] == 'Y')
                mlx_put_image_to_window(data->mlx, data->win, data->enemies, k*50, j*50);
            k++;
		}
		j++;
	}
    compteur_pas(data);
}