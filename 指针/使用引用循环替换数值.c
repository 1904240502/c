/*
���� a, b �� c ��ֵ: 3 5 6
����ǰ:
a = 3
b = 5
c = 6
������:
a = 6
b = 3
c = 5
*/
#include<stdio.h>
 
void cyclicSwap(int *a,int *b,int *c);
 
int main()
{
    int a, b, c;
 
    printf("���� a, b �� c ��ֵ: ");
    scanf("%d %d %d",&a,&b,&c);
 
    printf("����ǰ:\n");
    printf("a = %d \nb = %d \nc = %d\n",a,b,c);
 
    cyclicSwap(&a, &b, &c);
 
    printf("������:\n");
    printf("a = %d \nb = %d \nc = %d",a, b, c);
 
    return 0;
}
void cyclicSwap(int *a,int *b,int *c)
{
 
    int temp;
 
    // ����
    temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}
