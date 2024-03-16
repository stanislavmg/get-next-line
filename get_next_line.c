#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    long ch;
    long i;

	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
	line = NULL;
	ch = get_line(buf);
	if (!ch)
		ch = read(fd, buf, BUFFER_SIZE);
	while (ch > 0)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			if ('\n' == buf[i])
			{
				i++;
				line = ft_strjoin(line, buf, (size_t)i);
				ft_memmove(buf, buf + i, (size_t)(ch - i + 1));
				return (line);
			}
			if (ch == i)
				line = ft_strjoin(line, buf, (size_t)ch);
			i++;
		}
		ch = read(fd, buf, BUFFER_SIZE);
	}
    return (line);
}

long	get_line(char *buf)
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
