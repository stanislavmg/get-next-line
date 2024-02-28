#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    size_t ch;
    size_t i;

    i = 0;
	line = get_line(buf);
    while ((ch = read(fd, buf, BUFFER_SIZE)) > 0)
    {
		while (i < BUFFER_SIZE && i < ch)
		{
			if (buf[i] == '\n')
        	{
				if (!line)
            		line = ft_strdup(buf, i);
				else
					ft_strjoin(line, buf, i);
				if (i < ch)
					ft_memmove(buf, buf + i, ch - i);
            	return (line);
        	}
			i++;
		}
    }
    return (line);
}

char	*get_line(char *buf)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = 0;
	while (buf[i] && i < BUFFER_SIZE)
		i++;
	if (i < BUFFER_SIZE)
		line = ft_strdup(buf, i);
	if (!line)
		return (NULL);
	return (line);
}
