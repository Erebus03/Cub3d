/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:56:41 by araji             #+#    #+#             */
/*   Updated: 2025/11/06 17:42:03 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

static char	**clean(char **cells)
{
	int	i;

	i = 0;
	while (cells[i])
		free(cells[i++]);
	free(cells);
	return (NULL);
}

static char	**allocate_and_fill(char **cells, const char *s, int len, int k)
{
	int	j;

	j = 0;
	cells[k] = (char *)save((len + 1) * sizeof(char));
	if (!cells[k])
		return (NULL);
	while (j < len)
	{
		if (s[j] != '\n')
			cells[k][j] = s[j];
		else
			cells[k][j] = '\0';
		j++;
	}
	cells[k][j] = '\0';
	return (cells);
}

static char	**split_core(char **cells, const char *s, char c, int words)
{
	int	i;
	int	start;
	int	cellindex;

	i = 0;
	start = 0;
	cellindex = 0;
	while (s[i] && cellindex < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			if (allocate_and_fill(cells, &s[start],
					(i - start), cellindex) == NULL)
				return (NULL);
			cellindex++;
		}
	}
	cells[words] = NULL;
	return ((char **)cells);
}

static int	wordcount(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c, int *count)
{
	int		words;
	char	**strs_array;

	if (!s)
		return (NULL);
	words = wordcount(s, c);
	*count = words;
	strs_array = (char **)save((words + 1) * sizeof(char *));
	if (!strs_array)
	{
		return (NULL);
	}
	return (split_core(strs_array, s, c, words));
}
