/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:57:19 by zzin              #+#    #+#             */
/*   Updated: 2025/09/22 00:06:07 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_cub *c)
{
	if (key == XK_Escape)
		exitcub(c);
    // if (key == 13)
	// 	c->key_w = 1;
    // if (key == 1)
	// 	c->key_s = 1;
    // if (key == 0)
	// 	c->key_a = 1;
    // if (key == 2)
	// 	c->key_d = 1;
    return (0);
}

void	run(t_cub *c)
{
	int	x;
	int	y;

	mlx_get_screen_size(c->mlx, &x, &y);
	printf("x=%d\ny=%d\n", x, y);
	c->win = mlx_new_window(c->mlx, x, y, "zcub");
	// mlx_mouse_hide(c->mlx, c->win);
	mlx_hook(c->win, 2, 1L<<0, key_press, c);
    mlx_loop(c->mlx);
}
