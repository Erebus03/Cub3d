/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:06:02 by zzin              #+#    #+#             */
/*   Updated: 2025/11/07 23:07:07 by zzin             ###   ########.fr       */
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

void	clear_rcast(t_rcast *rc)
{
	t_mlx	*m;

	if(!rc)
		return ;
	if(!rc->mlx)
		return ;
	m = rc->mlx;
	//if(m->mlx)
	//	mlx_destroy_display(m->mlx);
	return ;
}

void	clear_heap(void)
{
	t_heap	*curr;

	if(!cubs)
		return ;
	if(!cubs->heap)
	{
		free(cubs);
		cubs = NULL;
		return ;
	}
	//clear_rcast(cubs->rcast);
	while (cubs->heap)
	{
		curr = cubs->heap;
		if (cubs->heap->data)
			free(cubs->heap->data);
		cubs->heap = cubs->heap->next;
		free(curr);
	}
	free(cubs);
	cubs = NULL;
	return ;
}

