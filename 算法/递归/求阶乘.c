#include<stdio.h>
int num(int n);
int main()
{
    int n;
    int sum;
    printf("���������֣�");
    scanf("%d",&n);
    sum=num(n);
    printf("%d�Ľ׳�Ϊ%d",n,sum);
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