#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    long ch;
    long i;

	line = get_line(buf);
	if (0 >= fd || 0 >= BUFFER_SIZE)
		return (NULL);
    while (0L > (ch = read(fd, buf, BUFFER_SIZE)))
    {
		i = 0;
		while (buf[i] != '\n' && i < BUFFER_SIZE && i < ch)
			i++;
		if (!line)
            line = ft_strdup(buf, (size_t)(i + 1));
		else
			ft_strjoin(line, buf, (size_t)(i + 1));
		if (i < ch)
			ft_memmove(buf, buf + i, (size_t)(ch - i));
		if ('\n' == buf[i] || i == ch)
        	return (line);
    }
    return (line);
}

char	*get_line(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && i < BUFFER_SIZE)
		i++;
	if (i < BUFFER_SIZE)
		return(ft_strdup(buf, i + 1));
	return (NULL);
}
