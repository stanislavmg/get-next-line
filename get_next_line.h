#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
long	get_first_line(char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src, size_t len);
void	ft_memmove(char *dst, char *src, size_t len);
char	*ft_strjoin(char *line, char *buf, size_t size);

#endif
