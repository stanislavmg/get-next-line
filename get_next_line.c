#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    long ch;
    long i;

	line = get_line(buf);
	printf("%p\n", line);
	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
    while (0 > (ch = read(fd, buf, BUFFER_SIZE)))
    {
		i = 0;
		while (buf[i] != '\n' && i < BUFFER_SIZE && i < ch)
			i++;
		if (!line)
            line = ft_strdup(buf, (size_t)i);
		else
			ft_strjoin(line, buf, (size_t)i);
		if (i < ch && i != 0)
			ft_memmove(buf, buf + i, (size_t)(ch - i));
		if ('\n' == buf[i] || i == ch)
        	return (line);
    }
    return (NULL);
}

char	*get_line(char *buf)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (0 == buf[i])
			return(ft_strdup(buf, i));
		i++;
	}	
	return (NULL);
}
