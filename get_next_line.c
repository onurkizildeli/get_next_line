/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:35:40 by mkizilde          #+#    #+#             */
/*   Updated: 2023/08/02 21:15:25 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*s;
	char	temp[1];
	int		i;
	int		temp_size;
	int		a;

	i = 0;
	a = 0;
	temp_size = 0;

	i = 0;
	fd = open("hede.txt", O_RDONLY, 0777);

		s = (char *)malloc(sizeof(char) * BUFFER_SIZE +1);
	while (read(fd, temp, BUFFER_SIZE))
	{
		a++;
		temp_size++;
		if (temp[0] == '\n')
			break ;
		s[i] = temp[0];
		i++;
	}
	s[i] = '\0';
	printf("\ns = %s \n", s);
	printf("temp = %s \n", temp);
	return (s);
}