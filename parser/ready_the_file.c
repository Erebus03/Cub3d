/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_the_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:12:16 by araji             #+#    #+#             */
/*   Updated: 2025/11/07 23:05:18 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubparser.h"

int	loop_over_lines(t_cub **data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nEmpty file\n", 18);
		close(fd);
		return (0);
	}
	while (line)
	{
		if (!empty_line(line))
		{
			if (!extract_data(line, data))
				return (0);
		}
		line = get_next_line(fd);
	}
	return (1);
}

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

int	init_struct(t_cub **data)
{
	int	i;

	//save?
	(*data) = malloc(sizeof(t_cub));
	if (!(*data))
		return (write(2, "Error\nMemory allocation failed\n", 32), 0);
	(*data)->heap = NULL;
	(*data)->map = NULL;
	(*data)->rcast = NULL;
	i = -1;
	while (++i < 4)
		(*data)->textures[i] = NULL;
	i = -1;
	while (++i < 4)
	{
		(*data)->flr_rgb[i] = -1;
		(*data)->ceiling_rgb[i] = -1;
	}
	(*data)->mwidth = 0;
	(*data)->mheight = 0;
	(*data)->player_pos[0] = -1;
	(*data)->player_pos[1] = -1;
	(*data)->plyr_count = 0;
	return (1);
}

int	parse_file(char *filename, t_cub **data)
{
	int		fd;

	if (!check_extension(filename))
		return (0);
	if (!init_struct(data))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nFailed to open file\n", 27), 0);
	if (!loop_over_lines(data, fd))
		return (close(fd), 0);
	if (!verify_map_boundaries(data))
		return (close(fd), 0);
	(*data)->ceiling_rgb[0] = create_rgb((*data)->ceiling_rgb[1],
			(*data)->ceiling_rgb[2], (*data)->ceiling_rgb[3]);
	(*data)->flr_rgb[0] = create_rgb((*data)->flr_rgb[1],
			(*data)->flr_rgb[2], (*data)->flr_rgb[3]);
	return (close(fd), 1);
}
