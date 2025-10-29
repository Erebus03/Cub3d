/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:11:55 by araji             #+#    #+#             */
/*   Updated: 2025/10/18 16:45:26 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

static int	found_newline(t_list *node)
{
	int	i;

	i = 0;
	node = ft_lstlast(node);
	if (!node)
		return (0);
	while (node->str[i])
	{
		if (node->str[i] == '\n')
		{
			i++;
			node->len = i;
			return (1);
		}
		i++;
	}
	node->len = i;
	return (0);
}

static void	extract(t_list *lst, char **line)
{
	int		i;
	int		j;

	if (!lst)
		return ;
	i = get_line_len(lst);
	if (!i)
		return ;
	*line = malloc(i + 1);
	if (!*line)
		return ;
	i = 0;
	while (lst && lst->str)
	{
		j = 0;
		while (lst->str[j] && j < lst->len)
			(*line)[i++] = lst->str[j++];
		lst = lst->next;
	}
	(*line)[i] = '\0';
}

static void	clean(t_list **lst)
{
	t_list	*lst_last;
	t_list	*new_start_node;
	char	*new_str;
	int		i;
	int		start;

	start = 0;
	lst_last = ft_lstlast(*lst);
	if (!lst_last)
		return ;
	new_str = lst_last->str;
	start = lst_last->len;
	lst_last->str = NULL;
	ft_lstclear(lst);
	i = 0;
	if (new_str[start] != '\0')
	{
		while (new_str[start])
			new_str[i++] = new_str[start++];
		new_str[i] = '\0';
		new_start_node = ft_lstnew(new_str);
		lst_add_back(lst, new_start_node);
	}
	else
		free(new_str);
}

static void	create_list(t_list **lst, int fd)
{
	ssize_t	bytes_read;
	t_list	*new_node;

	bytes_read = 0;
	while (found_newline(*lst) == 0)
	{
		new_node = ft_lstnew(NULL);
		new_node->str = malloc((size_t)BUFFER_SIZE + 1);
		if (!new_node)
			return ;
		bytes_read = read(fd, new_node->str, (size_t)BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
		{
			free(new_node->str);
			free(new_node);
			return ;
		}
		new_node->str[bytes_read] = '\0';
		lst_add_back(lst, new_node);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	char			*extracted_line;

	extracted_line = NULL;
	if (fd < 0 || (size_t)BUFFER_SIZE <= 0)
	{
		free(head);
		return (NULL);
	}
	create_list(&head, fd);
	if (!head)
		return (NULL);
	extract(head, &extracted_line);
	clean(&head);
	return (extracted_line);
}
