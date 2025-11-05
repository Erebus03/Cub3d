/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:46:20 by zzin              #+#    #+#             */
/*   Updated: 2025/11/05 11:24:51 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HFILES_H
# define HFILES_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
	int		mwidth;
	int		mheight;
	t_heap	*heap;
}	t_cub;

#endif
