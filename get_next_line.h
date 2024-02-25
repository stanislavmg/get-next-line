#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 128
# define SIZE 1024

char    *get_next_line(int fd);
char    *line_resize(char *tmp_line, size_t i);
char	*ft_strdup(const char *src, size_t len);
size_t  line_cpy(char *src, char *dst, size_t ch);

#include <unistd.h>
#endif