/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_the_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:12:16 by araji             #+#    #+#             */
/*   Updated: 2025/10/30 21:08:03 by zzin             ###   ########.fr       */
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

	// allocate memory for the struct
	// init that shiit

	(*data) = malloc(sizeof(t_cub));
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
		write(2, "Error\nEmpty file\n", 18);
		// return (close(fd), 0);
		close(fd);
		return (0);
	}
	while (line)
	{
		if (!empty_line(line))
		{
			// if (!extract_data(line + skip_leading_whitespace(line), data))
			if (!extract_data(line, data))
			{
				close(fd); return (0);
			}
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
