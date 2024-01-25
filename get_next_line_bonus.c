/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:50:57 by dkoca             #+#    #+#             */
/*   Updated: 2024/01/24 22:50:59 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	v.line[fd] = readbuf(v.buf, v.next[fd], v.br, fd);
	free(v.buf);
	v.buf = NULL;
	if (v.line[fd] == NULL)
		return (free(v.next[fd]), v.next[fd] = NULL, NULL);
	while (v.line[fd][v.len] != '\n' && v.line[fd][v.len] && v.line[fd][v.len
		+ 1] != '\0')
		v.len++;
	if (!v.line[fd][v.len])
		return (free((void *)v.line[fd]), v.line[fd] = NULL, v.next[fd] = NULL,
			NULL);
	v.next[fd] = ft_substr(v.line[fd], v.len + 1, ft_strlen(v.line[fd])
			- v.len);
	v.line[fd][v.len + 1] = '\0';
	v.len = 0;
	return (v.line[fd]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*file;
// 	const char *another_file;
// 	int			newFd;
// 	int			i;
// 	char		*ptr;
// 	char *str;
// 	int anfd;

// 	file = "example";
// 	i = 0;
// 	another_file = "another_example";
// 	newFd = open(file, O_RDONLY, 0644);
// 	anfd = open(another_file, O_RDONLY, 0644);
// 	while (i < 50)
// 	{
// 		ptr = get_next_line(newFd);
// 		printf("\nfile 1 = %s\n", ptr);
// 		str = get_next_line(anfd);
// 		printf("\nfile 2 = %s\n", str);
// 		i++;
// 		free(ptr);
// 		free(str);
// 	}
// 	close(newFd);
// 	close(anfd);
// }
