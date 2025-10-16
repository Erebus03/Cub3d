/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcast.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:40:59 by zzin              #+#    #+#             */
/*   Updated: 2025/10/16 20:35:52 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCAST_H
#define RCAST_H

#include "../cub.h"
#include "mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	int		x;
	int		y;
	void	*win;
}	t_mlx;

typedef struct s_rcast
{
	t_mlx *mlx;

}	t_rcast;

void	init_cub(void);
void	init_mlx(t_mlx *m);

#endif