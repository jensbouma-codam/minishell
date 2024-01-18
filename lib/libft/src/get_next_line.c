/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 19:18:22 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 15:04:16 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static char	*set_buffer_and_line(char *buffer, char *line)
{
	size_t	i;
	size_t	x;
	char	*new;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	x = -1;
	while (line[i + ++x + 1])
		buffer[x] = line[i + x + 1];
	line[i + 1] = '\0';
	new = NULL;
	if (line[0])
	{
		new = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!new)
			return (free(line), NULL);
		i = -1;
		while (line[++i])
			new[i] = line[i];
		return (free(line), new);
	}
	return (free(line), ret_empty(buffer));
}

/**
 * @brief Get the next line object from File descriptor
 * 
 * @param fd File descriptor
 * @return char* Next Line
 */
char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (ret_empty(buffer[fd]));
	line = ft_strcat(NULL, buffer[fd]);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n') && read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		if (buffer[fd][0])
			line = ft_strcat(line, buffer[fd]);
		if (!line)
			return (ret_empty(buffer[fd]));
	}
	return (set_buffer_and_line(buffer[fd], line));
}
