#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	char 		*line;
	long 		ch;
	long 		i;

	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
	line = NULL;
	ch = get_line(buf);
	if (!ch)
		ch = read(fd, buf, BUFFER_SIZE);
	while (ch > 0)
	{
		i = 0;
		while (i < ch)
		{
			if ('\n' == buf[i])
			{
				line = ft_strjoin(line, buf, (size_t)i + 1);
				if (i + 1 < ch)	
					ft_memmove(buf, buf + i + 1, (size_t)(ch - i));
				return (line);
			}
			else if (ch == i + 1)
				line = ft_strjoin(line, buf, (size_t)ch);
			i++;
			printf("i=%ld\n", i);
		}
		ch = read(fd, buf, BUFFER_SIZE);
		printf("ch=%ld\n", ch);
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
