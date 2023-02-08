#include "so_long.h"
int pos_x(t_list *data)
{
    int     x;
	int     y;
	
	x = 0;
	while (data->map[x] != 0)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
    return (0);
}

int pos_y(t_list *data)
{
    int     x;
	int     y;
	
	x = 0;
	y = 0;
	while (data->map[x] != 0)
	{
		y = 0;
		while (data->map[x][y] != '\0')
		{
			if (data->map[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
    return (0);
}

int event(int key, t_list *data)
{
    int x;
    int y;

    x = pos_x(data);
    y = pos_y(data);
    if (key == 119)
        w_mov(data,x,y);
    else if (key == 97)
        a_mov(data,x,y);
    else if (key == 115)
        s_mov(data,x,y);
    else if (key == 100)
        d_mov(data,x,y);
    refresh(data);
    return 1;
}