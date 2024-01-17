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
#include <stdio.h>
char *get_next_line(int fd)
{
	static vars v;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	v.buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!v.buf)
		return (NULL);
	if (v.br == -1)
		return (free(v.buf), NULL);
	if (v.line)
		return(free(v.line), v.line = NULL, get_next_line(fd));
	v.br = read(fd, v.buf, BUFFER_SIZE);
	// v.br = 1;
	while (v.br > 0 && (!ft_strchr(v.buf, '\n')))
	{
		v.line = ft_strjoin(v.line, v.buf);
		v.br = read(fd, v.buf, BUFFER_SIZE);
	}
	if (!v.line)
		return(NULL);
	v.line[ft_strchr(v.line, '\n') - v.line + 1] = '\0';
	v.buf += (ft_strchr(v.buf, '\n') - v.buf);
	return (v.line);
}

int main()
{
	const char *file;
	int newFd;

	file = "example";
	newFd = open(file, O_RDONLY, 0644);

	// get_next_line(newFd);
	// get_next_line(newFd);
	// get_next_line(newFd);

	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));
	printf("%s", get_next_line(newFd));


}
