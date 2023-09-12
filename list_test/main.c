#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
    int age;
    float salary_per_hour;
    
};
struct intern
{
    int age;
    float salary_per_hour;
    
} jenn;

typedef struct new_list
{
    char *data;
    char *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list.data = content;
    t_list.next = NULL;
}

int main()
{
    int age = 10;

    struct employee jan, bill, george;
    jan.age = 25;

    printf("%d", jan.age);

    printf("\nenter bill's age");

    scanf("%d", &bill.age);
    printf("bill's age is = %d", bill.age);

    printf("\nenter jenn's age");
    scanf("%d", &jenn.age);
    printf("jenn's age is = %d", jenn.age);

    return 0;
}