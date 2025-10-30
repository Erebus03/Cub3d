/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:39:33 by zzin              #+#    #+#             */
/*   Updated: 2025/10/30 18:34:46 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"

void	init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	mlx_get_screen_size(m->mlx, &m->x, &m->y);
	//m->win = mlx_new_window();
}

void	init_cub(void)
{
	t_mlx	m;
	
	init_mlx(&m);
}
