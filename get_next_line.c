/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:38:49 by mkizilde          #+#    #+#             */
/*   Updated: 2023/10/23 17:25:18 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_a_line(char *save, int fd)
{
	char	*buffer;
	int		read_bytes;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
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
		if (!next_next_line)
			return (NULL);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = get_a_line(save, fd);
	if (!save)
		return (NULL);
	line = extract_line(save);
	save = handle_next_line(save);
	return (line);
}
