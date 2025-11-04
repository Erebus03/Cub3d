/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:56 by araji             #+#    #+#             */
/*   Updated: 2025/11/04 21:51:29 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_cub	*cubs;

int main(int ac, char **av)
{
	cubs = NULL;
	if (ac != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}
	if (!parse_file(av[1], &cubs))
	{
		return (clear_heap(), 1);
	}
	
	
	// int i = 0;
	// for (i = 0; i < cubs->mheight; i++)
	// {
	// 	printf("Map line %d: '%s'\n", i, cubs->map[i]);
	// }
	printf("\nheight: %d, width: %d\n", cubs->mheight, cubs->mwidth);


	clear_heap();
	return (0);
}
