/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:20:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/01/09 00:21:17 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	return (sub);
}

char	*readbuf(char *buf, char *line, int bytesread, int fd)
{
	bytesread = 1;
	while (bytesread > 0 && (!ft_strchr(buf, '\n')))
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
			return (NULL);
		buf[bytesread] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_vars	v;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	v.buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!v.buf)
		return (NULL);
	v.line = readbuf(v.buf, v.next, v.br, fd);
	free(v.buf);
	v.buf = NULL;
	if (v.line == NULL)
		return (free(v.next), v.next = NULL, NULL);
	while (v.line[v.len] != '\n' && v.line[v.len] && v.line[v.len + 1] != '\0')
		v.len++;
	if (!v.line[v.len])
		return (free(v.line), v.line = NULL, v.next = NULL, NULL);
	v.next = ft_substr(v.line, v.len + 1, ft_strlen(v.line) - v.len);
	v.line[v.len + 1] = '\0';
	v.len = 0;
	return (v.line);
}

// int	main(void)
// {
// 	const char	*file;
// 	int			newFd;
// 	int			i;
// 	char		*ptr;

// 	file = "example";
// 	i = 0;
// 	newFd = open(file, O_RDONLY, 0644);
// 	// do {
// 	// 	ptr = get_next_line(newFd);
// 	// 	printf("OUTPUT = {%s}", ptr);
// 	// 	i++;
// 	// 	free(ptr);
// 	// } while (ptr);

// 	while (i < 3)
// 	{
// 		ptr = get_next_line(newFd);
// 		printf("OUTPUT = {%s}", ptr);
// 		i++;
// 		free(ptr);
// 	}
// 	close(newFd);
// }
