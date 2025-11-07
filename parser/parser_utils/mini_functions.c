/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:03:00 by araji             #+#    #+#             */
/*   Updated: 2025/11/07 23:32:41 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	skip_leading_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int	data_collected(t_cub **data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if ((*data)->textures[i] == NULL)
			return (0);
	}
	// it'll start from 1 to 3 cuz 0 is the color value not the RGB
	i = 0;
	while (++i < 4)
	{
		if ((*data)->flr_rgb[i] == -1 || (*data)->ceiling_rgb[i] == -1)
			return (0);
	}
	return (1);
}

int	empty_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0' || *line == EOF)
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_closed(t_cub **data, int y, int x)
{
	//change bach '.' to space
	if (x == 0 || y == 0 || x == (*data)->mwidth - 1
		|| y == (*data)->mheight - 1)
	{
		if ((*data)->map[y][x] == '0')
			return (0);
	}
	if (((*data)->map[y][x] == '0')
		&& ((*data)->map[y - 1][x] == '.' || (*data)->map[y + 1][x] == '.'
		|| (*data)->map[y][x - 1] == '.' || (*data)->map[y][x + 1] == '.'))
		return (0);
	return (1);
}
