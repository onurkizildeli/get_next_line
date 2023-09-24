#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define	BUFFER_SIZE 42
#endif


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

int ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;

	return (i);
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

int	main(void)
{
	int		fd;
	int		read_byte;
	int		dosya;
	char	*buffer;
	char	s1[10] = "123456789";
	char	s2[10] = "abcdefghi";
	char	s3[10];
	char	*s4;
	char	*s5;
	char	*s6;


	// dosya = open("hede.txt", O_RDWR);

	s4 = (char *)malloc(sizeof(char) * 4);
	s5 = (char *)malloc(sizeof(char) * 6);

	s4 = "bok";
	s5 = "püsür";



	printf("ft_stlen = %d\n", ft_strlen(s1));
	printf("ft_stlen = %d\n", ft_strlen(s2));
	printf("ft_stlen = %d\n", ft_strlen(s4));
	printf("ft_stlen = %d\n", ft_strlen(s5));
	printf("ft_strjoin = %s\n", ft_strjoin(s1, s2));

	// free(s6);

	// printf("s1 = %s, s2 = %s, new = %s\n", s1, s2);
	// printf("s3 = %s, s4 = %s, new = %d\n", s3, s4);

	// read_byte = read(dosya, buffer, BUFFER_SIZE);
	// printf("\nread_byte = %d, buffer = %s, BUFFER_SIZE= %d\n", read_byte, buffer, BUFFER_SIZE);

	// printf("ft_strchr test = %s", ft_strchr("abcdefg", 'u'));


}