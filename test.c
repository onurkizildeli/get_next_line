#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif



size_t	ft_strlen(const char *str)
{
	//Bir fonksiyonun uzunluğunu ölçer ve döndürür.
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat_2(char *dest, const char src*, int add_len)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = ft_strlen(dest)+ add_len + 1;
	dest = (char *)malloc(sizeof(char) * size);

	while (dest[i])
		dest[i++];
	while (j <= add_len)
		dest[i++] = src[j+++];

	dest[i] = '\0';

	return (dest);
}

int main(void)
{
    char *s;
    int i;

    s = (char *)malloc(sizeof(char) * 10);
    s = "deneme123";
    i = ft_strlen(s + 3);

    printf("%d", i);
    return 0;

}