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