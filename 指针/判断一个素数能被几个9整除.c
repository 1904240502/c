#include<stdio.h>
long mod_prime(int n,int *count)
{
    long i = 9;
    while(i%n != 0)
    {
        i = i*10 + 9;
        (*count) ++;
    }
    return i;
}
int main(void)
{
    int prime,count = 1;
    long ret;
    printf("������һ������:\n");
    scanf("%d",&prime);
    ret = mod_prime(prime,&count);
    printf("����%d������%d��9��ɵ���%ld",prime,count,ret);
    return 0;
}