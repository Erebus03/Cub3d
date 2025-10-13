/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:53:57 by zzin              #+#    #+#             */
/*   Updated: 2025/09/24 18:06:52 by zzin             ###   ########.fr       */
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

int main()
{
	t_cub	c;
	init(&c);
	run(&c);
}
