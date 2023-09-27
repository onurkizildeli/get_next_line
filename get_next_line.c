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
	{
		save = (char *)malloc(sizeof(char)*1);
		save[0] = '\0';
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		if (BUFFER_SIZE <= 0 || fd < 0)
		{
			free (buffer);
			return (0);
		}
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	if (!save)
	{
		free (save);
		return (NULL);
	}
	return (save);
}

char	*extract_line(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	while (save[j] && save[j] != '\n')
	{
		line[j] = save[j];
		j++;
	}
	if (save[j] == '\n')
	{
		line[j] = '\n';
		line[j + 1] = '\0';
	}
	else
		line[j] = '\0';
	return (line);
}

char	*handle_next_line(char	*save)
{
	int		i;
	int		j;
	char	*next_next_line;

	i = 0;
	j = 0;
	if (ft_strchr(save, '\n'))
	{
		while (save[i] != '\n')
			i++;
		next_next_line = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
		i++;
		while (save[i])
			next_next_line[j++] = save[i++];
		next_next_line[j] = '\0';
		free (save);
		return (next_next_line);
	}
	free(save);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	//char		*buffer;

	// buffer = (char *)malloc(sizeof(char)* (BUFFER_SIZE + 1));
	// buffer[BUFFER_SIZE] = '\0';

	// if (BUFFER_SIZE <= 0 || fd < 0)
	// {
	// 	free (buffer);
	// 	return (0);
	// }
	// if (buffer)
	// {
	// 	free(buffer);
	// 	return NULL;
	// }
	save = get_line(fd, save);
	if (!save)
		return (NULL);
	line = extract_line(save);
	save = handle_next_line(save);
	//free(buffer);
	return (line);
}
