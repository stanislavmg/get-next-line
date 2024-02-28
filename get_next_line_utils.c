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

char	*ft_strjoin(char const *line, char const *buf, size_t size)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	res = NULL;
	i = 0;
	j = 0;
	if (!line || !buf)
		return (NULL);
	len = ft_strlen(line) + size + 1;
	res = malloc(len);
	if (!res)
		return (NULL);
	while (line[j])
		res[i++] = line[j++];
	j = 0;
	while (j < size)
		res[i++] = buf[j++];
	res[i] = 0;
	free((void *) line);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	if (!dst && !src && len > 0)
		return (dst);
	d = dst;
	s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	d[len] = 0;
	return (dst);
}
