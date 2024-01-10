/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:21:31 by dkoca             #+#    #+#             */
/*   Updated: 2024/01/09 00:21:33 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*m;
	size_t			i;

	i = 0;
	m = malloc(count * size);
	if (!m)
		return (0);
	while (i < count * size)
	{
		m[i] = 0;
		i++;
	}
	return (m);
}

char	*ft_strdup(const char *s)
{
	char	*m;

	m = (char *)malloc(ft_strlen(s) + 1);
	if (!m)
		return (0);
	ft_strlcpy(m, s, ft_strlen(s) + 1);
	return (m);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
