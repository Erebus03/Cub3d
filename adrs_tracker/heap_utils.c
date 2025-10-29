/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:06:42 by zzin              #+#    #+#             */
/*   Updated: 2025/10/30 00:55:23 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	new_node(t_heap **stack, void *data)
{
	t_heap	*tmp;
	t_heap	*node;

	if (!data)
		return ;
	node = (t_heap *)malloc(sizeof(t_heap));
	if (!node)
		return ;
	node->data = data;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	g_new_node(t_heap **stack, void *data)
{
	t_heap	*tmp;
	t_heap	*node;

	if (!data)
		return ;
	node = (t_heap *)save(sizeof(t_heap));
	if (!node)
		return ;
	node->data = data;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

size_t	list_size(t_heap *list)
{
	t_heap	*curr;
	size_t	len;

	len = 0;
	if (!list)
		return (len);
	curr = list;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

//void	free_list(t_heap **head)
//{
//	t_heap	*tmp;
//
//	if (!head || !*head)
//		return ;
//	while (*head != NULL)
//	{
//		tmp = *head;
//		if ((*head)->data)
//			clear((*head)->data);
//		*head = (*head)->next;
//		free(tmp);
//	}
//	*head = NULL;
//}
