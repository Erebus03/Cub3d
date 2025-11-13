/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:49:04 by araji             #+#    #+#             */
/*   Updated: 2025/11/13 18:12:01 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_closed(t_cub **data, int y, int x)
{
	if (x == 0 || y == 0 || x == (*data)->mwidth - 1
		|| y == (*data)->mheight - 1)
	{
		if ((*data)->map[y][x] == '0')
			return (0);
	}
	if ((((*data)->map[y][x] == '0' || is_player((*data)->map[y][x])))
		&& ((*data)->map[y - 1][x] == ' ' || (*data)->map[y + 1][x] == ' '
		|| (*data)->map[y][x - 1] == ' ' || (*data)->map[y][x + 1] == ' '))
		return (0);
	return (1);
}
