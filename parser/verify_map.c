/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:44:04 by araji             #+#    #+#             */
/*   Updated: 2025/11/13 18:12:36 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubparser.h"

int	validate_map_chars(char *line, t_cub **data)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			// i didnt really think this through, mach ikhdem ghila b3da
			(*data)->plyr_count += 1;
			(*data)->player_pos[1] = i;
			(*data)->player_pos[0] = (*data)->mheight;
		}
		//change to space
		else if (line[i] != ' ' && line[i] != '0' && line[i] != '1')
		{
			write(2, "Error\nInvalid character in map\n", 32);
			printf("Invalid char: %c\n", line[i]);
			return (0);
		}
	}
	return (1);
}

int	pad_map_lines(t_cub **data)
{
	char	*newline;
	int		linelen;
	int		width;
	int		i;

	i = -1;
	width = (*data)->mwidth;
	while ((*data)->map[++i])
	{
		linelen = ft_strlen((*data)->map[i]);
		if (linelen < width)
		{
			newline = save(sizeof(char) * (width + 1));
			if (!newline)
				return (0);
			ft_memcpy(newline, (*data)->map[i], linelen);
			while (linelen < width)
				newline[linelen++] = ' ';
			newline[width] = '\0';
			(*data)->map[i] = newline;
		}
	}
	return (1);
}

/*	IN VERIFY_MAP_BOUNDARIES
	i filled (padded) the lines first so i can navigate freely to check for
	the map boundaries, to prevent going out of bounds (segfaults)
*/
int	verify_map_boundaries(t_cub **data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if ((*data)->plyr_count != 1)
		return (write(2, "Error\nOnly one player allowed\n", 30), 0);
	if (!pad_map_lines(data))
		return (0);
	while (y < (*data)->mheight)
	{
		x = 0;
		while (x < (*data)->mwidth)
		{
			if (!is_closed(data, y, x))
			{
				write(2, "Error\nMap is not closed/surrounded by walls\n", 44);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/*
	no need to free old map because its being tracked by the heap
*/
static char	**realloc_map(char **old, int old_size, int new_size)
{
	char	**new;
	int		i;

	new = save(sizeof(char *) * (new_size + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < old_size)
		new[i] = old[i];
	new[i] = NULL;
	return (new);
}

int	collect_map(char *line, t_cub **data)
{
	(*data)->map = realloc_map((*data)->map, (*data)->mheight,
			(*data)->mheight + 2);
	if (!(*data)->map)
		return (write(2, "Error\nMemory allocation failed\n", 32), 0);
	(*data)->map[(*data)->mheight] = ft_strdup(line);
	(*data)->map[(*data)->mheight + 1] = NULL;
	(*data)->mheight += 1;
	if ((int)ft_strlen(line) > (*data)->mwidth)
		(*data)->mwidth = ft_strlen(line);
	return (1);
}
