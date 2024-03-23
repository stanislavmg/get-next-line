#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct  s_list
{
    int             file;
    char            *str;
    struct s_list   *next;
} t_list;

char    *get_next_line(int fd);
long	get_line(char **r_val, char *buf, long ch);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src, size_t len);
void	ft_memmove(char *dst, char *src, size_t len);
char	*ft_strjoin(char *line, char *buf, size_t size);
t_list	*search_fd(int fd, t_list *list);
void	add_list(t_list **list, char *buf, int fd, long len);
void	del_node(t_list **list, t_list *node);
t_list *free_node(t_list *node);

#endif
