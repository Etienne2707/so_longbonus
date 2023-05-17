#include "so_long.h"

void check_map_arg(int argc , char *str)
{
    int i;

    i = 0;

    if (argc != 2)
    {
        return ;
    }
    
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
			&& str[i + 3] == 'r' && str[i + 4] == '\0')
			return ;
		i++;
	}
	write(2, "Invalid map\n", 12);
	exit(0);
}

void    check_file(char *map)
{
	char	buff[42];
	int		n;
	int		a;

	a = open(map, O_RDONLY);
	n = read(a, buff, 42);
	if (n < 0)
		return ;
	if (n == 0)
	{
		write(2, "Invalid map\n", 12);
		close (a);
		exit(0);
	}
	n = 0;
	while (buff[n] == '1')
		n++;
	if ((buff[n] != '\n' && buff[n] != '\0' ) || n == 0)
	{
		write(2, "Invalid map\n", 12);
		close (a);
		exit(0);
	}
	close (a);
	return ;
}