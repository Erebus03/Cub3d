/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:36:14 by araji             #+#    #+#             */
/*   Updated: 2025/11/05 11:35:53 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubparser.h"


int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*strip_line(char *line)
{
	char	*start;
	char	*end;

	if (!line)
		return (NULL);

	// printf("Original line: '%s'\n", line);
	//printf("Stripping line: '%s'\n", line);
	start = line;
	while (*start && ft_isspace(*start))
		start++;

	if (*start == '\0')
		return (ft_strdup("")); // only spaces

	end = start + ft_strlen(start) - 1;
	while (end > start && ft_isspace(*end))
		end--;

	*(end + 1) = '\0';

	return (ft_strdup(start));
}

int	check_texture(char *line, t_cub **data, t_texture tex_type)
{
	int		count;
	char	**split;
	
	count  = 0;
	split  = ft_split(strip_line(line), ' ', &count);
	if (count != 1)
	{
		write(2, "Error\nInvalid texture line format\n", 35);
		//while (*split)
		//	free(*split++);
		return (0);
	}
	(*data)->textures[tex_type] = ft_strdup(split[0]);		// build

	//while (*split)
	//	free(*split++);

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
	split  = ft_split(strip_line(line), ',', &count);
	if (count != 3)
	{
		//while (*split) {free(*split++);}
		return (write(2, "Error\nInvalid color line format\n", 33), 0);
	}
	if (is_floor)
	{
		while (++i < 3)
			(*data)->flr_rgb[i + 1] = atoi(strip_line(split[i]));
	} else {
		while (++i < 3)
			(*data)->ceiling_rgb[i + 1] = atoi(strip_line(split[i]));
	}
	//while (*split) {free(*split++);}
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

int validate_map_chars(char *line, t_cub **data)
{
	int i;

	i = -1;
	// printf("Validating map line: '%s'\n\n", line);
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			// i didnt really think this through, mach ikhdem ghila b3da
			(*data)->player_pos[1] = i;
			(*data)->player_pos[0] = (*data)->mheight + 1;
		}
		//change to space
		else if (line[i] != '.' && line[i] != '0' && line[i] != '1')
		{
			write(2, "Error\nInvalid character in map\n", 32);
			return (0);
		}
	}
	// pad_line(&line, width);
	return (1);
}

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
	//garbage collector handels prev allocated map lines, so no need to free them
	return (new);
}


int	collect_map(char *line, t_cub **data)
{

	(*data)->map = realloc_map((*data)->map, (*data)->mheight, (*data)->mheight + 2);
	if (!(*data)->map)
		return (write(2, "Error\nMemory allocation failed\n", 32), 0);
	
	(*data)->map[(*data)->mheight] = ft_strdup(line);
	(*data)->map[(*data)->mheight + 1] = NULL;
	
	(*data)->mheight += 1;
	if ((int)ft_strlen(line) > (*data)->mwidth)
		(*data)->mwidth = ft_strlen(line);

	return (1);
}

int extract_data(char *line, t_cub **data)
{
	
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		return (get_textures(line, data));
	else if (line[0] == 'F' || line[0] == 'C')
		return (get_colors(line, data));
	else if (data_collected(data) &&
		(line[0] == '1' || line[0] == '0' || line[0] == '.'))//change to space
	{
		if (validate_map_chars(line, data))
			return (collect_map(line, data));
		else
			return (0);
	}
	else
		return (write(2, "Error\nInvalid line in file config part\n", 40), 0);
}
