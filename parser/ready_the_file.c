/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_the_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:12:16 by araji             #+#    #+#             */
/*   Updated: 2025/11/05 14:40:39 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubparser.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(&filename[len - 4], ".cub") != 0)
	{
		write(2, "Error\nInvalid file extension\n", 30);
		return (0);
	}
	return (1);
}

int init_struct(t_cub **data)
{
	int	i;

	(*data) = malloc(sizeof(t_cub)); //save?
	if (!(*data))
	{
		write(2, "Error\nMemory allocation failed\n", 32);
		return (0);
	}
	(*data)->heap = NULL;
	i = -1;
	while (++i < 4)
		(*data)->textures[i] = NULL;
	i = -1;
	while (++i < 4)
	{
		(*data)->flr_rgb[i] = -1;
		(*data)->ceiling_rgb[i] = -1;
	}	
	(*data)->map = NULL;
	(*data)->mwidth = 0;
	(*data)->mheight = 0;
	(*data)->player_pos[0] = -1;
	(*data)->player_pos[1] = -1;
	return (1);
}

static int pad_map_lines(t_cub **data)
{
	char *newline;
	int linelen;
	int width;
	int i;

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
				newline[linelen++] = '.';
			newline[width] = '\0';
			(*data)->map[i] = newline;
		}
	}
	return (1);
}

static int is_closed(t_cub **data, int y, int x)
{
	// check all around if there's a space or out of bounds
	// if so return 0
	// else return 1

	// printf("line	%d:	'%s'\n", y, (*data)->map[y]);
	// printf("Checking position (%d, %d) with value '%c'\n\n", y, x, (*data)->map[y][x]);
	

	//change bach '.' to space
	if (((*data)->map[y][x] == '0')
		&& ((*data)->map[y-1][x] == '.' || (*data)->map[y+1][x] == '.'
		|| (*data)->map[y][x-1] == '.' || (*data)->map[y][x+1] == '.'))
		return (0);
	return (1);
}
static int	verify_map_boundaries(t_cub **data)
{
	int y = 0, x = 0;

	// should pad the lines first so i can navigate freely to check for the map boundaries

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

int	parse_file(char *filename, t_cub **data)
{
	int fd;
	char *line;

	if (!check_extension(filename))
		return (0);
	if (!init_struct(data))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nFailed to open file\n", 27), 0);	
	line = get_next_line(fd);
	if (!line)
	{
		return (write(2, "Error\nEmpty file\n", 18), close(fd), 0);
	}
	while (line)
	{
		if (!empty_line(line))
		{
			if (!extract_data(line, data))
			{
				return (close(fd), 0);
			}
		}
		line = get_next_line(fd);
	}
	if (!verify_map_boundaries(data))
		return (close(fd), 0);
	
	close(fd);
	return (1);
}
