/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:47:15 by zzin              #+#    #+#             */
/*   Updated: 2025/10/30 20:50:33 by zzin             ###   ########.fr       */
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
