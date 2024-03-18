#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct  s_list
{
    int     node;
    char    *str;
    struct s_list  *next;
} t_list;

char    *get_next_line(int fd);
long	get_first_line(char *buf);
long	get_line(char *r_val, char *buf, long ch);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src, size_t len);
void	ft_memmove(char *dst, char *src, size_t len);
char	*ft_strjoin(char *line, char *buf, size_t size);
t_list	*search_fd(int fd, t_list *list);
void	add_list(t_list *list, char *buf, int fd);
void	del_list(t_list *list);

#endif
