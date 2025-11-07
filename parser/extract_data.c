/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:36:14 by araji             #+#    #+#             */
/*   Updated: 2025/11/06 17:51:38 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubparser.h"

int	check_texture(char *line, t_cub **data, t_texture tex_type)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_split(strip_line(line), ' ', &count);
	if (count != 1)
	{
		write(2, "Error\nInvalid texture line format\n", 35);
		return (0);
	}
	(*data)->textures[tex_type] = ft_strdup(split[0]);
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
		return (write(2, "Error\nInvalid texture identifier\n", 34), 0);
}

int	check_color(char *line, t_cub **data, int is_floor)
{
	int		i;
	int		count;
	char	**split;

	i = -1;
	count = 0;
	split = ft_split(strip_line(line), ',', &count);
	if (count != 3)
	{
		return (write(2, "Error\nInvalid color line format\n", 33), 0);
	}
	if (is_floor)
	{
		while (++i < 3)
			(*data)->flr_rgb[i + 1] = atoi(strip_line(split[i]));
	}
	else
	{
		while (++i < 3)
			(*data)->ceiling_rgb[i + 1] = atoi(strip_line(split[i]));
	}
	return (1);
}

int	get_colors(char *line, t_cub **data)
{
	if (line[0] == 'F')
		return (check_color(line + 1, data, 1));
	else if (line[0] == 'C')
		return (check_color(line + 1, data, 0));
	else
		return (write(2, "Error\nInvalid color identifier\n", 32), 0);
}

/*
	Note: FOR THE STRIP LINE FUNCTION
	if the line has only spaces, split a valid pointer pointing to
	an empty string, meaning the texture path is valid but missing,
	in this case the rayceter function is what should throw an error later
		because it didnt find the texture file.
	FHEMTI? HH
*/
int	extract_data(char *line, t_cub **data)
{
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		return (get_textures(line, data));
	else if (line[0] == 'F' || line[0] == 'C')
		return (get_colors(line, data));
	else if (data_collected(data) //change to space
		&& (line[0] == '1' || line[0] == '0' || line[0] == '.'))
	{
		if (validate_map_chars(line, data))
			return (collect_map(line, data));
		else
			return (0);
	}
	else
		return (write(2, "Error\nInvalid line in file config part\n", 40), 0);
}
