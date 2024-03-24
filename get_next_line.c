#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;

	if (0 > fd || 0 >= BUFFER_SIZE)
		return (NULL);
	line = handle_file_input(buf, fd);
	return (line);
}

char	*handle_file_input(char *buf, int fd)
{
	char	*line;
	long	ch;
	long	i;

	line = NULL;
	ch = get_first_line(buf);
	if (!ch)
		ch = read(fd, buf, BUFFER_SIZE);
	while (ch > 0)
	{
		i = -1;
		while (++i < ch)
		{
			if ('\n' == buf[i] || ch - 1 == i)
			{
				i++;
				line = ft_strjoin(line, buf, (size_t)i);
				ft_memmove(buf, buf + i, (size_t)(ch - i));
				i = ft_strlen(line) - 1;
				if (line && '\n' == line[i])
					return (line);
			}
		}
		ch = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

long	get_first_line(char *buf)
{
	long	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == 0)
			return (i);
		i++;
	}
	return (0);
}
