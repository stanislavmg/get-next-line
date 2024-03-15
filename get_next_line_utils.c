#include "get_next_line.h"

char	*ft_strdup(const char *src, size_t len)
{
	char	*dst;
	size_t	i;

	if (!src)
		return (NULL);
	if (!len)
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
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

char	*ft_strjoin(char *line, char *buf, size_t size)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	res = NULL;
	i = 0;
	j = 0;
	if (!line)
		return (ft_strdup(buf, size));
	len = (ft_strlen(line) + size + 1);
	res = (char *)malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (line[j])
		res[i++] = line[j++];
	j = 0;
	while (j < size)
		res[i++] = buf[j++];
	res[i] = 0;
	free(line);
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

void	ft_memmove(char *dst, char *src, size_t len)
{
	size_t	i;

	if (!dst || !src || !len)
		return ;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}
