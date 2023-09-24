/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:41:10 by mkizilde          #+#    #+#             */
/*   Updated: 2023/09/13 18:41:10 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line_bonus.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

ft_strlen2(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;

	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == (char) c)
		return ((char*)(s + i));
	return NULL;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char)
			* (ft_strlen2(s1, '\0') + ft_strlen2(s2, '\0') + 1));

	if (!new)
		return (NULL);

	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';

	return (new);
}


char	*get_line(int fd, char *save)
{
	char	*buffer;
	int		read_byte;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_byte = 1;
	while (read_byte > 0 && !ft_strchr(save, '\n'))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		*save = ft_strjoin(save, buffer);
	}
	return (save);
}

char	*extract_line(char *save)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen2(save, '\n');
	line = (char *)malloc(sizeof(char) * size + 2);
	while(save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = save[i];
	line[size + 2] = '\0';

	return (line);
}

char	*get_leftover(char *save)
{
	ft_strchr(save, '\n');
	
}

char	*get_next_line_bonus(int fd)
{
	static char	*save[FOPEN_MAX];
	char		*line;

	save[fd] = get_line(fd, *save[fd]);
	line = extract_line(save[fd]);
	save[fd] = get_leftover(save[fd]);
	return (line);
}

int	main(void)
{
	int dosya;

	dosya = open("hede.txt", O_RDWR | O_CREAT);

	get_next_line_bonus(dosya);
	return (0);
}
