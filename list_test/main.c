/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkizilde <mkizilde@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:36:17 by mkizilde          #+#    #+#             */
/*   Updated: 2023/09/13 15:36:17 by mkizilde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


struct list_test1
{
	int data;
	char *next;
}list1;

struct s_employee
{
	int		age;
	float	salary_per_hour;
	char	position[20];
};
struct s_intern
{
	int age;
	float salary_per_hour;
	
} jenn;

// struct intern
// {
//     int age;
//     float salary_per_hour;
	
// };

struct s_homes_at_street
{
	char building_name[20];
	int apt_numbers;
	int numbers;
};

typedef struct book_test {
	char	book_id[50];
	int		release_year;
	int		stock;
}books;


typedef struct {
	char	book_id[50];
	int		release_year;
	int		stock;
}magz;


int main()
{
	struct s_intern jen, abby;
	jen.age = 25;
	jen.salary_per_hour = 35;
	
	books 	once;
	magz	two;

	once.stock = 35;
	two.release_year = 1987;

	printf("%d\n", jen.age);
	printf("%.2f", jen.salary_per_hour);

	return 0;
}

