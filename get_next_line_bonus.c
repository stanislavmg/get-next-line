#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	char 			*buf;
	static t_list	*list;
	t_list			*last_fd;
	char 			*r_val;
	long 			in_buf;
	long			ch_count;

	r_val = NULL;
	buf = NULL;
	in_buf = 0;
	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	last_fd = search_fd(fd, list);
	if (last_fd)
	{
		in_buf = get_line(&r_val, last_fd->str, ft_strlen(last_fd->str));
		if (!in_buf)
			del_node(&list, last_fd);
		if ('\n' == r_val[ft_strlen(r_val) - 1])
		{
			free(buf);
			return (r_val);
		}
	}
	ch_count = read(fd, buf, BUFFER_SIZE);
	while (!in_buf && ch_count)
	{
		in_buf = get_line(&r_val, buf, ch_count);
		if (in_buf)
			add_list(&list, buf, fd, in_buf);
		if ('\n' == r_val[ft_strlen(r_val) - 1])
		{
			free(buf);
			return (r_val);
		}
		ch_count = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (r_val);
}

long	get_line(char **r_val, char *buf, long ch)
{
	long	i;

	i = 0;
	while (i < ch)
	{
		if ('\n' == buf[i] || ch - 1 == i)
		{
			i++;
			*r_val = ft_strjoin(*r_val, buf, (size_t)i);
			ft_memmove(buf, buf + i, (size_t)(ch - i));
			return (ch - i);
		}
		i++;
	}
	return (0);
}

t_list	*search_fd(int fd, t_list *list)
{
	while (list)
	{
		if (list->file == fd)
			return (list);
		list = list->next;
	}
	return(NULL);
}

void add_list(t_list **list, char *buf, int fd, long len)
{
    t_list *current;
    t_list *prev;
    t_list *new_node;
	
	prev = NULL;
	current = *list;
	new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return ;
    new_node->str = ft_strdup(buf, len);
    if (!new_node->str)
    {
        free(new_node);
        return ;
    }
    new_node->file = fd;
    while (current && fd > current->file)
    {
        prev = current;
        current = current->next;
    }
    if (!prev)
        *list = new_node;
    else
        prev->next = new_node;
    new_node->next = current;
}

void del_node(t_list **list, t_list *node)
{
    t_list *prev;
    t_list *current;

    prev = NULL;
	current = *list;
    if (current == node)
	{
        *list = node->next;
        free(node->str);
		free(node);
        return ;
    }
    while (current && current != node)
	{
        prev = current;
        current = current->next;
    }
    if (current)
	{
        prev->next = current->next;
		free(current->str);
        free(current);
    }
}