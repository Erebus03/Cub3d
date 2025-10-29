/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:06:02 by zzin              #+#    #+#             */
/*   Updated: 2025/10/30 00:23:31 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	*save(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	new_node(&cubs->heap, p);
	return (p);
}

//void	unsave(t_heap **lst, void *adress)
//{
//	t_heap	*curr;
//	t_heap	*prev;
//
//	if (!adress || !lst || !*lst)
//		return ;
//	curr = *lst;
//	prev = NULL;
//	while (curr)
//	{
//		if (curr->data == adress)
//		{
//			if (prev == NULL)
//				*lst = curr->next;
//			else
//				prev->next = curr->next;
//			free(curr->data);
//			free(curr);
//			return ;
//		}
//		prev = curr;
//		curr = curr->next;
//	}
//}

void	clear_heap(void)
{
	t_heap	*curr;

	if (!cubs || !cubs->heap)
		return ;
	while (cubs->heap)
	{
		curr = cubs->heap;
		if (cubs->heap->data)
			free(cubs->heap->data);
		cubs->heap = cubs->heap->next;
		free(curr);
	}
	return ;
}

