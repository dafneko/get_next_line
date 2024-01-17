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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slength;

	slength = ft_strlen(src);
	if (!size)
		return (slength);
	size -= 1;
	while ((*src) && size--)
		*dst++ = *src++;
	*dst = '\0';
	return (slength);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(size, sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, size);
	free((void *)s1);
	return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if ((!dst || !src))
		return (0);
	if (dlen >= size)
		return (slen + size);
	while ((*dst) && --size > 0)
		dst++;
	while ((*src) && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (slen + dlen);
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