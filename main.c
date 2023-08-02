/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:54:49 by mkizilde          #+#    #+#             */
/*   Updated: 2023/08/02 20:38:09 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

/*
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
	//s = (char *)malloc(sizeof(char) * temp_size);
	i = 0;
	fd = open("hede.txt", O_RDONLY, 0777);
		//s = (char *)malloc(sizeof(char) * temp_size);
		s = (char *)malloc(sizeof(char) * temp_size);
	while (a < 8)
	{
		a++;
		read(fd, temp, BUFFER_SIZE);
		//temp_size += read(fd, temp, 1);
		temp_size++;
		s[i] = temp[0];
		i++;
	}
	s[i] = '\0';
	printf("\ns = %s \n", s);
	printf("temp = %s \n", temp);
	return (s);
}
*/

int main()
{
	int			dosya;
	char		*str;
	int			a;
	
	//dosya = open("hede.txt", O_RDONLY, 0777);
	//read (dosya, str, 1);
	//printf("%d\n", a);
	
	//get_next_line(dosya);
	printf("%s", get_next_line(0));
	return 0;
}