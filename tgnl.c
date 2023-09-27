/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:37:09 by mkizilde          #+#    #+#             */
/*   Updated: 2023/09/17 01:37:09 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <get_next_line_bonus.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int	ft_strlen2(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;

	return (i);
}

int ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
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
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_size;

	s_size = ft_strlen(s);
	if (start >= s_size)
		return (ft_strdup(""));
	if (len > s_size)
		len = s_size - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

char	*get_line(int fd, char *save)
{
	char	*buffer;
	int		i;
	int		read_byte;

	if (!save)
	{
		save = (char *)malloc(sizeof(char)*1);
		save[0] = '\0';
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	read_byte = 1;
	while (read_byte > 0 && !ft_strchr(save, '\n'))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		//printf("buffer = %s", buffer);
		save = ft_strjoin(save, buffer);
	}
	return save;
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
	line[size + 1] = '\0';

	return (line);
}

char	*get_leftover(char *save)
{
	int	i;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;

	save = ft_strchr(save, '\n');
	printf("leftover save = %s", save);
}

// char *get_next_line(int fd, char save)
// {
// 	//static char	*save[OPEN_MAX];
// 	char		*p;

// 	p = ft_strchr(save, '\n')
// 	printf("test p = %p", p);
// 	get_line(int fd, char *save)
// }




int	main(void)
{
	int		read_byte;
	int		dosya;
	char	*buffer;
	char	s1[10] = "123456789";
	char	s2[10] = "abcdefghi";
	char	s3[10];
	char	*s4;
	char	*s5;
	char	*s6;
	static char	*save[FOPEN_MAX];
	// char		*p;

	// p = ((char *)malloc(sizeof(char *) * ft_strlen2(save[1], '\n')));
	// p = ft_strchr(save[1], '\n');
	save[1] = (char *)malloc(sizeof(char) * 14);
	save[1] = "hede\n1234567";
	dosya = open("hede.txt", O_RDWR);

	s4 = (char *)malloc(sizeof(char) * 4);
	s5 = (char *)malloc(sizeof(char) * 6);
	// save[1] = (char *)malloc(sizeof(char));
	// save[1][0] = '\0';

	s4 = "bok";
	s5 = "püsür";

	//printf("test p = %p", p);
	// printf("fd is = %d\n", dosya);
	// printf("save[1] is = %s\n", save[1]);
	printf("ft_strjoin = %s\n", get_line(dosya, save[1]));
	printf("ft_strchr test = %s\n", ft_strchr(save[1], '\n'));

	printf("\nsave1 test = %s", extract_line(save[1]));
	get_leftover(save[1]);

}



	// printf("ft_stlen = %d\n", ft_strlen(s1));
	// printf("ft_stlen = %d\n", ft_strlen(s2));
	// printf("ft_stlen = %d\n", ft_strlen(s4));
	// printf("ft_stlen = %d\n", ft_strlen(s5));
	// printf("ft_strjoin = %s\n", ft_strjoin(s1, s2));

	// free(s6);

	// printf("s1 = %s, s2 = %s, new = %s\n", s1, s2);
	// printf("s3 = %s, s4 = %s, new = %d\n", s3, s4);

	// read_byte = read(dosya, buffer, BUFFER_SIZE);
	// printf("\nread_byte = %d, buffer = %s, BUFFER_SIZE= %d\n", read_byte, buffer, BUFFER_SIZE);

	// printf("ft_strchr test = %s", ft_strchr("abcdefg", 'u'));