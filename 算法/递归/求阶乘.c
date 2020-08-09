#include<stdio.h>
int num(int n);
int main()
{
    int n;
    int sum;
    printf("请输入数字：");
    scanf("%d",&n);
    sum=num(n);
    printf("%d的阶乘为%d",n,sum);
    return 0;
}
int num(int n)
{
    if(n==1)
    {
        return n;
    }
    else
    {
        return n*num(n-1);
    }
}