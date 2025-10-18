/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:56 by araji             #+#    #+#             */
/*   Updated: 2025/10/18 16:59:16 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int ac, char **av)
{
	t_cub	*data = NULL;
	if (ac != 2)
	{
		write(2, "Invalid number of arguments\n", 29);
		return (1);
	}

	if (parse_file(av[1], &data) == 0)
	{
		
		// free the struct and its members
		return (1);
	}

	// for (int i = 0; i < 4; i++)
	// 		printf("textures: >%s<\n", data->textures[i]);
	return (0);
}
