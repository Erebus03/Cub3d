/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji <araji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:47:15 by zzin              #+#    #+#             */
/*   Updated: 2025/11/06 18:04:43 by araji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubparser.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	while (n--)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (d);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dest;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	dest = save(size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, size);
	return (dest);
}

char	*strip_line(char *line)
{
	char	*start;
	char	*end;

	if (!line)
		return (NULL);
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
