#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    long ch;
    long i;

    i = 0;
	
	line = get_line(buf);
	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
    while (0 > (ch = read(fd, buf, BUFFER_SIZE)))
    {
		while (i < BUFFER_SIZE && i < ch)
		{
			if ('\n' == buf[i] || BUFFER_SIZE == i + 1)
        	{
				if (!line)
            		line = ft_strdup(buf, (size_t)i);
				else
					ft_strjoin(line, buf, (size_t)i);
				if (i < ch)
					ft_memmove(buf, buf + i, (size_t)(ch - i));
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
