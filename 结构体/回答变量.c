#include<stdio.h>

struct student
{
    int x;
    char c;
} a;

/* º¯ÊýÉùÃ÷ */
struct student f(struct student *b);

int main()
{
    a.x=3;
    a.c='a';
    f(&a);
    printf("%d,%c",a.x,a.c);

    return 0;
}

struct  student f(struct student *b)
{
    b ->x = 20;
    b->c ='y';
}