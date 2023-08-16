/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psuedo_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 01:40:54 by mkizilde          #+#    #+#             */
/*   Updated: 2023/08/12 01:40:54 by mkizilde         ###   ########.fr       */
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

/*!SECTION

Sorular????

* bytes_read'i fonksiyona geçirirken int vs gibi tanımlama yapmak gerekiyormu?
* temp = *bytes_read + check_line(bytes_read); doğru bir atama şeklimi 
	yoksa while loopamı almak gereliyor.

*/

size_t	ft_strlen(const char *str)
{
	//Bir string'in uzunluğunu ölçer ve döndürür.
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_line(buffer)
{
	//Buffer'ın içinde '\n' karakteri var mı varsa kaçıncı indekste olduğunu kontrol eder.
	//Eğer yoksa 0 döndürür bu şekilde control statement içinde kullanılır.
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer == '\n')
			return (i + 1);
		i++;
	}
	return (0);
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

char *store_leftover(buffer)
{
	/*!SECTION
	Bu fonksiyon buffer'da '\n' karakterini görürse 
	'\n' karakterinden sonraki karakterleri bir sonraki satıra eklemek için depolar
	Aynı zamanda sayfa başı ise veya  artık karakter kalmadıysa kontrol state'inde 
	kontrol edilmek için kullanılır.
	if(store_leftover(buffer)) gibi??
	*/

	char	*leftover;
	int		i;
	int		j;

	j = 0;
	i = check_line(buffer);
	leftover = (char *)malloc(sizeof(char) * 1)
	if (i > 0)
	{
		(char *)malloc(sizeof(char) * ft_strlen(leftover + i));
		while (buffer)
		{
			leftover[j] = *buffer[i];
			j++;
			i++;
		}
	}

	return (leftover);
}

char *add_leftover(buffer, char *leftover_str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!leftover_str || leftover_str[0] == '\0')
		return (NULL);

	temp = (char *)malloc(sizeof(char) * ft_strlen(leftover_str));
	whilie (leftover_str)
	{
		temp[i] = *leftover_str[i];
		i++;
	}

	return (temp);
}

char *merge_str(buffer, char *line)
{
	//char	*temp;
	int		i;
	int		j;

	i = 0;
	//temp = add_leftover(buffer, leftover_str);

	if (!check_line(buffer))
	{
		ft_strcat_2(line, buffer, ft_strlen(buffer))
	}
	else
	{
		ft_strcat_2(line, buffer, check_line(buffer))
	}

	return (line);
}

char	*get_next_line(int fd)
{
	//while döngüsü içerisinde kullanılınca ekrana dosyadan her seferinde 1 satır yazdıracak
	char		*leftover;
	char		*line;
	static char	*buffer;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = read(fd, buffer, BUFFER_SIZE);
	buffer[i] = '\0';

	line = add_leftover(buffer, leftover);
	merge_str(buffer, line);
	free (leftover);
	leftover = store_leftover(buffer);
	return (line);
}

// int	main(void)
// {
// 	//int		fd;
// 	char	*s;


// 	int fd = open("hede.txt", O_RDONLY);

// 	if (fd == -1) 
// 	{
//         perror("open");
//         return 1;
//     }

// 	while (s = get_next_line(fd))
// 	{
// 	printf("%s \n", s);

// 	}
	
// 	return (0);
	
// }





/*!SECTION
char *add_leftover(buffer, )
{
	// Bu fonksiyon Eğer bir önceki satır okumasındaki buffer'da '\n'
	// karakterinden sonra artık karakter kaldıysa bunu temp'e ekler
	char	*temp;
	char	*leftover_str;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * 1);
	temp = NULL;
	leftover_str = store_leftover;

	if (leftover_str)
	{
		temp = (char *)malloc(sizeof(char) * ft_strlen(leftover_str));
		temp[i++] = leftover_str++;
	}
	return (temp);
}



char *merge_str(buffer, char *line)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	//temp = add_leftover(buffer, leftover_str);

	if (!check_line(buffer))
	{
		j = ft_strlen(temp);
		temp = (char *)malloc(sizeof(char) * ft_strlen(buffer) 
				+ ft_strlen(temp));
		while (buffer)
			*temp + j++ = buffer[i++];
	}
	else
	{
		while (buffer[j] != '\n')
			buffer[j++];
		temp = (char *)malloc(sizeof(char) * j + ft_strlen(leftover_str));
		while (*buffer != '\n')
			temp[i] = buffer++;
	}

	return (temp);
}

*/















/*************  GET_NEXT_10_BYTES ***************/


/*
char *get_next_10_bytes(int fd) {
    static char buffer[BUFFER_SIZE + 1]; // Tampon
    ssize_t read_result = read(fd, buffer, BUFFER_SIZE);
    
    if (read_result <= 0) {
        return NULL; // Dosya sonuna geldik veya hata oldu
    }

    buffer[read_result] = '\0'; // Okunan veriyi sonlandır
    return buffer; // Tamponu döndür
}

int main(void) {
    int fd = open("hede.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char *s;
	s = get_next_10_bytes(fd);
    //while ((s = get_next_10_bytes(fd)) != NULL) {
        printf("%s\n", s);
    //}

    close(fd);
    return 0;
}

*/