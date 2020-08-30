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
    printf("请输入一个素数:\n");
    scanf("%d",&prime);
    ret = mod_prime(prime,&count);
    printf("素数%d能整除%d个9组成的数%ld",prime,count,ret);
    return 0;
}