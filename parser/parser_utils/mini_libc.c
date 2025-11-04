/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:33:27 by araji             #+#    #+#             */
/*   Updated: 2025/11/03 20:55:36 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

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

	//return (1); // for now
	i = -1;
	while (++i < 4)
	{
		if ((*data)->textures[i] == NULL)
			return (0);
	}
	i = 0; // it'll start from 1 to 3 cuz 0 is the color value not the RGB
	while (++i < 4)
	{
		if ((*data)->flr_rgb[i] == -1 || (*data)->ceiling_rgb[i] == -1)
			return (0);
	}
	return (1);
}

size_t	ft_strlen(char *filename)
{
	size_t	len;

	len = 0;
	while (filename[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	empty_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0' || *line == EOF)
		return (1);
	return (0);
}
