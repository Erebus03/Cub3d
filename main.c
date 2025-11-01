/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:56 by araji             #+#    #+#             */
/*   Updated: 2025/11/01 04:26:20 by araji            ###   ########.fr       */
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
	clear_heap();
	return (0);
}
