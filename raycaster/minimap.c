/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:19:33 by zzin              #+#    #+#             */
/*   Updated: 2025/10/14 00:03:45 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	square(t_cub *c, int x, int y)
{
	int	w;
	int	h;

	h = y;
	while(h <= c->minmap.square_size)
	{
		w = x;
		while (w <= c->minmap.square_size)
		{
			mlx_pixel_put(c->mlx, c->win, w, h, 0x663399);
			w++;
		}
		h++;
	}
}

void	draw_minimap(t_cub *c)
{
	printf("%s\n", c->map[0]);
	//printf("%s\n", *c->map);
	//printf("%zu\n", ft_strlen(c->map[0]));
	square(c, 0, 0);
	//printf("%d", (50 * 50) / 100);
	//mlx_put_image_to_window(c->mlx, c->win, )
}
