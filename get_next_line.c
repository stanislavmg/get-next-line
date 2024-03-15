#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    long ch;
    long i;

	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
	i = 0;
	line = get_line(buf);
	ch = read(fd, buf, BUFFER_SIZE);
	while (ch > 0)
	{
		while (i < BUFFER_SIZE)
		{
			if ('\n' == buf[i] || i == ch)
			{
				line = ft_strjoin(line, buf, (size_t)i + 1);
				ft_memmove(buf, buf + i + 1, (size_t)(ch - i));
				return (line);
			}
			i++;
		}
		ch = read(fd, buf, BUFFER_SIZE);
	}
    return (NULL);
}

char	*get_line(char *buf)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == 0)
			return (ft_strdup(buf, i));
		i++;
	}
	return (NULL);
}
