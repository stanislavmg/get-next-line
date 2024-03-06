#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *get_line(char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char *line, char *buf, size_t size);

#endif
