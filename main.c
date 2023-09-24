/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:39:27 by mkizilde          #+#    #+#             */
/*   Updated: 2023/08/16 23:39:27 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	//static char	*save;
	char	*line;
	// static char	*s1;
	// char	*s2;


	//s1 = (char *)malloc(sizeof(char) * 11);
	// s2 = (char *)malloc(sizeof(char) * 6);
	//s1 = "";
	// s2 = "abcd";

	// char s3[10] = "132456789";
	// char s4[5] = "abcd";
	//new = ft_strjoin(s3, s4);
	// printf("\n %s \n", ft_strjoin(s1, s2));

	//int dosya = open("big_line_with_nl", O_RDONLY);

	//line = get_next_line(dosya);
    // printf("Line: %s\n", line);
	//printf("get_line in main = %s", get_line(dosya, save));
	//free(save);
    // while (i<6)
    // {
    //     printf("Line: %s\n", get_next_line(dosya));
    //     //free(line);
	// 	i++;
    // }




    while ((line = get_next_line(0)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }

	printf("\nFOPEN_MAX: %d\n", FOPEN_MAX);

	return 0;
}