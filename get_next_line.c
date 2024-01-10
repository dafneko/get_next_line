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
	const char *file;
	int newFd;
	char	*buff;
	int		br;

	(void)fd;
	buff = ft_calloc(sizeof(char), 1001);
	file = "example";
	newFd = open(file, O_RDONLY, 0644);
	br = read(newFd, buff, 1000);
	buff[br] = 0; //everything i read is in buff
	printf("buff = %s\n", buff);
	return (NULL);
}

int	main()
{
	get_next_line(0);
}