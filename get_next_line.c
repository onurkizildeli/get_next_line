/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:39:38 by mkizilde          #+#    #+#             */
/*   Updated: 2023/08/16 23:39:38 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*get_line(int fd, char *save)
{
	char	*buffer;
	int		read_bytes;

	if (!save)
		save = ft_strjoin("", "");
	if (ft_strchr(save, '\n'))
		return (save);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*extract_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = ft_substr(save, 0, i+1);

	return (line);
}

char	*handle_next_line(char	*save)
{
	int		i;
	char	*next_next_line;

	i = 0;
	if (ft_strchr(save, '\n'))
	{
		while (save[i] != '\n')
			i++;

		next_next_line = ft_substr(save, i + 1, ft_strlen(save) - i +1);

		return (next_next_line);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buffer;
	// char		*leftover;
	// char		*backup;

	buffer = (char *)malloc(sizeof(char)* (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	save = get_line(fd, save);
	if (!save)
		return (NULL);
	line = extract_line(save);
	save = handle_next_line(save);
	//backup = save;

	return (line);
}
