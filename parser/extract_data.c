/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:36:14 by araji             #+#    #+#             */
/*   Updated: 2025/10/18 19:53:32 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubparser.h"

int	check_texture(char *line, t_cub **data, t_texture tex_type)
{
	// (void)tex_type;
	// (void)data;
	// (void)line;
	int	count = 0;
	char **split  = ft_split(line, ' ', &count);
	// (void)split;
	if (count != 1)
	{
		printf("more than one element in this bitch\n");
		write(2, "Invalid texture line format\n", 29);
		while (*split)
			free(*split++);
		return (0);
	}
	(*data)->textures[tex_type] = strdup(split[0]);		// build
	
	while (*split)
		free(*split++);

	return (1);
}

int	get_textures(char *line, t_cub **data)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (check_texture(line + 2, data, NO)); 
	else if (line[0] == 'S' && line[1] == 'O')
		return (check_texture(line + 2, data, SO));
	else if (line[0] == 'W' && line[1] == 'E')
		return (check_texture(line + 2, data, WE));
	else if (line[0] == 'E' && line[1] == 'A')
		return (check_texture(line + 2, data, EA));
	else
		return (write(2, "Invalid texture identifier\n", 28), 0);
}

int	check_color(char *line, t_cub **data, int is_floor)
{
	(void)is_floor;
	(void)data;
	(void)line;
	int	count;

	count = 0;
	char **split  = ft_split(line, ',', &count);
	if (count != 3)
	{
		write(2, "Invalid color line format\n", 27);
		while (*split)
			free(*split++);
		return (0);
	}
	printf("R:%s\nG:%s\nB:%s\n", split[0], split[1], split[2]);

	while (*split)
		free(*split++);
	
	return (1);
}

int	get_colors(char *line, t_cub **data)
{
	if (line[0] == 'F')
		return (check_color(line + 1, data, 1));
	else if (line[0] == 'C')
		return (check_color(line + 1, data, 0));
	else
		return (write(2, "Invalid color identifier\n", 26), 0);
}

int	get_map(char *line, t_cub **data)
{
	(void)data;
	(void)line;
	write(2, "Parsing map line\n", 18);
	// append line to map
	return (1);
}

int extract_data(char *line, t_cub **data)
{
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		return (get_textures(line, data));
	else if (line[0] == 'F' || line[0] == 'C')
		return (get_colors(line, data));
	else if (data_collected(data) &&
		(line[0] == '1' || line[0] == '0' || line[0] == ' '))
	{
		return (get_map(line, data));
	}
	else
		return (write(2, "Invalid line in file config part\n", 34), 0);
}
