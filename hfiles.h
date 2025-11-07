/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:46:20 by zzin              #+#    #+#             */
/*   Updated: 2025/11/07 22:38:10 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HFILES_H
# define HFILES_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
	t_heap	*heap;
}	t_cub;

#endif
