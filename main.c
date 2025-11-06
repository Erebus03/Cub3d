/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:56 by araji             #+#    #+#             */
/*   Updated: 2025/11/06 16:31:24 by araji            ###   ########.fr       */
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
	
	int i = 0;
	for (i = 0; i < cubs->mheight; i++)
	{
		printf("Map line %d:	'%s'\n", i, cubs->map[i]);
	}
	printf("\nheight: %d, width: %d\n", cubs->mheight, cubs->mwidth);

	printf("\nPlayer position: (%d, %d)\n", cubs->player_pos[0], cubs->player_pos[1]);
	printf("Number of players: %d\n", cubs->plyr_count);
	printf("Textures:\n");
	printf("NO: %s\n", cubs->textures[NO]);
	printf("SO: %s\n", cubs->textures[SO]);
	printf("WE: %s\n", cubs->textures[WE]);
	printf("EA: %s\n", cubs->textures[EA]);
	printf("Floor RGB: %d, %d, %d\n", cubs->flr_rgb[RED], cubs->flr_rgb[GREEN], cubs->flr_rgb[BLUE]);
	printf("Ceiling RGB: %d, %d, %d\n", cubs->ceiling_rgb[RED], cubs->ceiling_rgb[GREEN], cubs->ceiling_rgb[BLUE]);
	printf("Floor Color Value:	%d (hex:	%x	%X)\n", cubs->flr_rgb[FULL], cubs->flr_rgb[FULL], cubs->flr_rgb[FULL]);
	printf("Ceiling Color Value:	%d (hex:	%x	%X)\n", cubs->ceiling_rgb[FULL], cubs->ceiling_rgb[FULL], cubs->ceiling_rgb[FULL]);
	clear_heap();
	return (0);
}
