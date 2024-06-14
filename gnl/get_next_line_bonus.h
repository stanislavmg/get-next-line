/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoremyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:37:51 by sgoremyk          #+#    #+#             */
/*   Updated: 2024/03/24 13:46:03 by sgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				file;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*handle_file_input(t_list **list, char *buf, int fd, t_list *last_fd);
void	add_node(t_list **list, char *buf, int fd, long len);
void	del_node(t_list **list, t_list *node);
t_list	*search_file(int fd, t_list *list);
long	get_line(char **r_val, char *buf, long ch);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src, size_t len);
void	ft_memmove(char *dst, char *src, size_t len);
char	*ft_strjoin(char *line, char *buf, size_t size);

#endif
