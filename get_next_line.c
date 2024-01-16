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
	// printf("buf = %s\n", v.buf);
	v.buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!v.buf)
		return (NULL);
	if (v.br == -1)
		return (free(v.buf), NULL);
	v.br = 1;
	while (v.br > 0 && (!ft_strchr(v.buf, '\n')))
	{
		v.br = read(fd, v.buf, BUFFER_SIZE);
		v.line = ft_strjoin(v.next, v.buf);
		// printf("buf = %s\n", v.buf);
	}
	if (!v.line)
		return(NULL);
	v.end = ft_strchr(v.line, '\n');
	v.buf += (v.end - v.line + 1);
	v.next = ft_strjoin(v.buf, "");
	v.line[v.end - v.line + 1] = '\0';
	printf("res = %s\n", v.line);
	free(v.buf);
	v.buf = NULL;
	return (free(v.line), v.line = NULL, NULL);
}

int main()
{
	const char *file;
	int newFd;

	file = "example";
	newFd = open(file, O_RDONLY, 0644);

	get_next_line(newFd);
	// get_next_line(newFd);
	// get_next_line(newFd);
}
