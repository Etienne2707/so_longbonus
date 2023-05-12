#include "so_long.h"


int roadmap(char **str)
{
    int x;
    int y;

    x = 1;
    while (str[x] != 0)
    {
        y = 1;
        while (str[x][y] != '\0')
        {
            if (str[x][y] == 'C')
                return 0;
            y++;
        }
        x++;
    }
    return 1;
}

void    ft_croix_axe_x(char **str, int x , int y)
{
    int a;
    int b;

    a = x;
    b = y;
    while (str[++x][y] == '0' || str[x][y] == 'C')
        str[x][y] = 'x';
    x = a;
    while (str[--x][y] == '0' || str[x][y] == 'C' )
        str[x][y] = 'x';

}

void    ft_croix(char **str, int x, int y)
{
    int a;
    int b;
    int i;
    a = x;
    b = y;
    i = 0;
    while (str[x][++y] == '0' || str[x][y] == 'C')
        str[x][y] = 'x';
    y = b;
    while (str[x][--y] == '0' || str[x][y] == 'C')
        str[x][y] = 'x';
    ft_croix_axe_x(str,a,b);
}

void start(char **str)
{
    int y;
    int x;

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

char **path_check(char **map)
{
    int x;
    int y;
    char **str;

    x = 0;
    str = gnl_and_check();
    while (str[x] != 0)
    {
        y = 0;
        while (str[x][y] != '\0')
        {
            if (str[x][y] == 'P')
                break ;
            y++;
        }
        if (str[x][y] == 'P')
                break ;
        x++;
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