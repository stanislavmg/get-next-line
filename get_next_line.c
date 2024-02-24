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
    if (!line)
        return (NULL);
    while ((ch = read(fd, buf, BUFFER_SIZE)) != 0)
    {
        i += line_cpy(buf, tmp_line + i, ch);
        if (i % SIZE == 0)
            tmp_line = line_resize(tmp_line, i % SIZE + 1);
        if (!tmp_line)
            return (NULL);
        if (tmp_line[i] == '\n')
        {
            line_cpy(tmp_line, line, i);
            free(tmp_line);
            return (line);
        }
    }
    return (line);
}

char *line_resize(char *tmp_line, size_t i)
{
    char *t;

    t = (char *)malloc(SIZE * i);
    if (!t)
    {
        free(tmp_line);
        return (NULL);
    }
    line_cpy(tmp_line, t);
    tmp_line = t;
    return (tmp_line);
}

size_t line_cpy(char *src, const char *dst, size_t ch) // добавить кол-во прочитанных байт
{
    size_t i;

    i = 0;
    while (src[i - 1] != '\n' && i < BUFFER_SIZ && i < ch)
    {
        dst[i] = src[i];
        src[i] = 0;
        i++;
    }
    return (i);
}