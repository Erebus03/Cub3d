/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:11:39 by araji             #+#    #+#             */
/*   Updated: 2025/10/30 21:03:55 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	get_line_len(t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		i = i + tmp->len;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		//free((*lst)->str);
		//free(*lst);
		*lst = tmp;
	}
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new_node;

	new_node = save(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->str = content;
	new_node->len = 0;
	new_node->next = NULL;
	return (new_node);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
