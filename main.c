/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:56 by araji             #+#    #+#             */
/*   Updated: 2025/10/28 21:38:01 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int ac, char **av)
{
	t_cub	*data = NULL;
	if (ac != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}

	if (parse_file(av[1], &data) == 0)
	{
		
		// free the struct and its members
		return (1);
	}

	printf("\n\n\n");
	for (int i = 0; i < 4; i++)
		printf("textures: >%s<\n", data->textures[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("floor rgb; >%d<\n", data->flr_rgb[i]);
	printf("\n");
	for (int i = 0; i < 4; i++)
		printf("ceiling rgb; >%d<\n", data->ceiling_rgb[i]);

	return (0);
}
