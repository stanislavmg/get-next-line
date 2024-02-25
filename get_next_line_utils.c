#include "get_next_line.h"

char	*ft_strdup(const char *src, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(len);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
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

size_t line_cpy(char *src, char *dst, size_t ch)
{
    size_t i;

    i = 0;
    while (src[i] != '\n' && i < BUFFER_SIZE && i < ch)
    {
        dst[i] = src[i];
        if (BUFFER_SIZE > 1)
            src[i] = 0;
        i++;
    }
    return (i);
}