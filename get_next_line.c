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
	v.buf = ft_calloc(BUFFER_SIZE + 1, sizeof(v.buf));
	if (!v.buf)
		return (NULL);
	if (v.br == -1)
		return (free(v.buf), NULL);
	v.br = 1;
	while (v.br > 0 && (!ft_strchr(v.buf, '\n')))
	{
		v.br = read(fd, v.buf, BUFFER_SIZE);
	printf("buf = %s\n", v.buf);

		if (!v.copy)
			v.copy = ft_strdup("");
		v.copy = ft_strjoin(v.copy, v.buf);
	printf("copy = %s\n", v.copy);

	}
	v.end = ft_strchr(v.copy, '\n');
	v.line = ft_substr(v.copy, 0, v.end - v.copy);
	printf("line = %s\n", v.line);
	return (free(v.copy), NULL);
}

int	main()
{
	const char *file;
	int newFd;

	file = "example";
	newFd = open(file, O_RDONLY, 0644);

	get_next_line(newFd);
	get_next_line(newFd);
	get_next_line(newFd);

}
