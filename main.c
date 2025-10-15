/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:56 by araji             #+#    #+#             */
/*   Updated: 2025/10/15 21:00:33 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_extension(char *filename)
{
	int	len;

	len = strlen(filename);
	if (len < 4 || strcmp(&filename[len - 4], ".cub") != 0)
	{
		write(2, "Error\nInvalid file extension\n", 30);
		return (0);
	}
	return (1);
}

int init_struct(t_cub *data)
{
	int	i;

	//allocate memory for the struct
	// init that shiit

	data = malloc(sizeof(t_cub));
	if (!data)
	{
		write(2, "Error\nMemory allocation failed\n", 32);
		return (0);
	}
	i = -1;
	while (++i < 4)
		data->textures[i] = NULL;
	while (++i < 4)
	{
		data->flr_rgb[i] = -1;
		data->ceiling_rgb[i] = -1;
	}	
	data->map = NULL;
	data->mwidth = 0;
	data->mheight = 0;
	return (1);
}
int	parse_file(char *filename, t_cub **data)
{
	int fd;
	char *line;
	// open the file
	// read line by line
	// parse each line
	// fill the struct
	// check for errors
	// close the file
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file\n", 27);
		return (0);
	}

	line = get_next_line(fd); // to build
	while (line)
	{
		// parse_line(line, data); // to build
		// get_data_from_line(line, data); // to build
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (1);
}
int main(int ac, char **av)
{
	t_cub	*data = NULL;
	if (ac != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}

	// this will take the av[1] as a filename and check if it ends with .cub
	if (check_extension(av[1]) == 0)
		return (1);

	// this will initialize the struct with default values (NULL, 0, etc.)
	if (init_struct(data) == 0)
		return (1);
	
	write(1, "Struct initialized successfully\n", 33);
	// free(data);

	if (parse_file(av[1], &data) == 0)
	{
		// free the struct and its members
		return (1);
	}
	return (0);
}