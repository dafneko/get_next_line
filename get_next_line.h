/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:21:47 by dkoca             #+#    #+#             */
/*   Updated: 2024/01/09 00:21:48 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct variables
{
	char	*buf; //everything i read is in buf
	int		br; //br is holding the count of bytes read
	// i need a variable to hold the words until new line is reached in case buffer size is less than where new line  is
	int len; // static variable are set to 0 when uninitialized, do i need this when br already keeps count of bytes read? Yes because br always counts the multiplications of BUFFER_SIZE (unless EOF) but len should get the length of the length of the bytes read until the new line
	int i;
	char *end;
	char *line;
	char *next;
	char *temp;
} vars;

// utils.c
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif