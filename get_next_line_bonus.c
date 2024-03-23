#include "get_next_line_bonus.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	char 			buf[BUFFER_SIZE];
	static t_list	*list;
	t_list			*last_fd;
	char 			*r_val;
	long 			inbuf;
	long			count;

	r_val = NULL;
	inbuf = 0;
	if (0 > fd || 0 >= BUFFER_SIZE || read(fd, buf, 0) < 0)
		return (NULL);
	last_fd = search_fd(fd, list);
	if (last_fd)
	{
		inbuf = get_line(&r_val, last_fd->str, ft_strlen(last_fd->str));
		if (!inbuf)
			del_list(&list, last_fd);
		if ('\n' == r_val[ft_strlen(r_val) - 1])
			return (r_val);
	}
	count = read(fd, buf, BUFFER_SIZE);
	while (!inbuf && count)
	{
		inbuf = get_line(&r_val, buf, count);
		if (inbuf)
			add_list(&list, buf, fd, inbuf);
		if ('\n' == r_val[ft_strlen(r_val) - 1])
			return (r_val);
		count = read(fd, buf, BUFFER_SIZE);
	}
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
		if (list->node == fd)
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
        return;
    new_node->str = ft_strdup(buf, len);
    if (!new_node->str)
    {
        free(new_node);
        return ;
    }
    new_node->node = fd;
    while (current && fd > current->node)
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

void	del_list(t_list **list, t_list *node)
{
	t_list	*tmp;

	if (*list == node)
	{
		free((*list)->str);
		free(*list);
		*list = NULL;
	}
	else if ((*list)->next == node)
	{
		free((*list)->next->str);
		free((*list)->next);
		(*list)->next = NULL;
	}
	else if (node->next)
	{
		tmp = node->next;
		free(node->str);
		*node = *node->next;
		free(tmp);
	}
	else if (!node->next)
	{
		tmp = *list;
		while (tmp->next != node)
			tmp = tmp->next;
		free(node->str);
		free(node);
		tmp->next = NULL;
	}
}