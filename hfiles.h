/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:46:20 by zzin              #+#    #+#             */
/*   Updated: 2025/11/12 17:31:49 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HFILES_H
# define HFILES_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include <X11/keysym.h>

typedef struct s_rcast
{
	void	*mlx;
	int		x;
	int		y;
	int		sq_size;
	int		psize;
	int		psquarex;
	int		psquarey;
	int		px;
	int		py;
	float	fx;//-1 -0.1 0 0.9  1
	float	fy;// 1
	void	*win;

}	t_rcast;

typedef struct hp
{
	void		*data;
	struct hp	*next;
}	t_heap;

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA
}	t_texture;

typedef enum e_color
{
	FULL,
	RED,
	GREEN,
	BLUE
}	t_color;

typedef struct s_cub
{
	char	*textures[4];	// NO, SO, WE, EA
	int		flr_rgb[4];		// [0] is the whole color, [1] R, [2] G, [3] B
	int		ceiling_rgb[4];	// [0] is the whole color, [1] R, [2] G, [3] B
	char	**map;
	int		player_pos[2]; // y x
	int		plyr_count;
	int		mwidth;
	int		mheight;
	t_rcast	*rcast;
	int key_w;
    int key_s;
    int key_a;
    int key_d;
	t_heap	*heap;
}	t_cub;

#endif
