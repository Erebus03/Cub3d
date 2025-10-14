/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:53:57 by zzin              #+#    #+#             */
/*   Updated: 2025/10/14 23:23:54 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub *c)
{
	int	x;
	int	y;

	c->mlx = mlx_init();
	if (!c->mlx)
		return verr("minilibx err.");
	mlx_get_screen_size(c->mlx, &x, &y);
	printf("x=%d\ny=%d\n", x, y);
	c->win = mlx_new_window(c->mlx, x, y, "zcub");
	parse(c);
	draw_minimap(c);
}

int main(int ac, char **av)
{
	t_cub	c;
	
	if (ac != 2)
		return (write(2, "Error: Incorrect number of arguments\n", 38), 1);
	if (check_extension_init())


	/*
	*	check extension and init parsing struct
	
	*	assign colors and textures
	
	*	built map and check it
	*/

	
	init(&c);
	
	run(&c);
}
