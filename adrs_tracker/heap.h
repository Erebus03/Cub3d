/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:13:03 by zzin              #+#    #+#             */
/*   Updated: 2025/10/30 00:53:26 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include "../cub.h"

void	*save(size_t size);
void	clear_heap(void);
void	g_new_node(t_heap **stack, void *data);
void	new_node(t_heap **stack, void *data);
size_t	list_size(t_heap *list);
void	free_list(t_heap **head);


//void	clear_heap(void);
//void	*save(size_t size);
//void	init_shell(void);
//size_t	list_size(t_heap *list);
//void	new_node(t_heap **stack, void *data);
//void	g_new_node(t_heap **stack, void *data);
//void	free_list(t_heap **head);
//void	unsave(t_heap **lst, void *adress);

#endif