#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	char 			buf[BUFFER_SIZE];
    static t_list	*list;
	t_list			*last_fd;
	char 			*r_val;
	long 			ch;
	long			count;

	r_val = NULL;
	list = NULL;
	ch = 0;
	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
	last_fd = search_fd(fd, list);
	if (last_fd)
	{
		ch = get_line(r_val, last_fd->str, ft_strlen(last_fd->str));
		if (!ch)
			del_list(last_fd);
		if (r_val[ft_strlen(r_val) - 1] == '\n')
			return (r_val);
	}
	count = read(fd, buf, BUFFER_SIZE);
	while (!ch && count)
	{
		ch = get_line(r_val, buf, count);
		count = read(fd, buf, BUFFER_SIZE);
	}
	if (ch)
		add_list(list, buf, fd);	
	return (r_val);
}

// char	*get_line(char *buf, long ch)
// {
// 	long	i;
// 	char 	*line;

// 	ch = read(fd, buf, BUFFER_SIZE);
// 	while (ch > 0)
// 	{
// 		i = 0;
// 		while (i < ch)
// 		{
// 			if ('\n' == buf[i] || ch - 1 == i)
// 			{
// 				i++;
// 				line = ft_strjoin(line, buf, (size_t)i);
// 				ft_memmove(buf, buf + i, (size_t)(ch - i));
// 				i = ft_strlen(line) - 1;
// 				if ('\n' == line[i])
// 					return (line);
// 			}
// 			i++;
// 		}
// 		ch = read(fd, buf, BUFFER_SIZE);
// 	}
// 	return (line);
// }
long	get_line(char *r_val, char *buf, long ch)
{
	long	i;

	i = 0;
	while (i < ch)
	{
		if ('\n' == buf[i] || ch - 1 == i)
		{
			i++;
			r_val = ft_strjoin(r_val, buf, (size_t)i);
			ft_memmove(buf, buf + i, (size_t)(ch - i));
			return (ch - i);
		}
		i++;
	}
	return (0);
}

t_list	*search_fd(int fd, t_list *list)
{
	while (list && list->node != fd)
		list = list->next;
	return(list);
}

void	add_list(t_list *list, char *buf, int fd)
{
	t_list	*prev;
	t_list	*new;
	
	prev = list;
	while (fd > list->node && list)
	{
		prev = list;
		list = list->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	prev->next = new;
	new->next = list;
	new->node = fd;
	new->str = ft_strdup(buf, ft_strlen(buf));
}

void	del_list(t_list *list)
{
	t_list	*tmp;

	tmp = list->next;
	free(list->str);
	*list = *(list->next);
	free(tmp);
}