#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    char *tmp_line;
    size_t ch;
    size_t i;

    tmp_line = (char *)malloc(SIZE);
    i = 0;
    if (!tmp_line)
        return (NULL);
    while (buf[i] == 0)
        i++;
    while ((ch = read(fd, buf, BUFFER_SIZE)) != 0)
    {
        if (ch == -1)
            return (NULL);
        if (buf[i] == '\n')
        {
            line = ft_strdup(tmp_line, i);
            free(tmp_line);
            return (line);
        }
        i += line_cpy(buf, tmp_line + i, ch);
        if (i % SIZE == 0)
            tmp_line = line_resize(tmp_line, i % SIZE + 1);
        if (!tmp_line)
            return (NULL);
    }
    return (line);
}
