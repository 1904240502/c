/*
公式：
    x%n=(x1%n * x2%n * x3%n* x4%n* x5%n)%n
    x=x1x2x3x4x5
取值相等情况则有：
    A%b=(a*a)%b=(a%b*a%b)%b
    无限将除数开方（幂指数除以2）,直到出现幂指数为1时停止此时所有余数之积再求余既是原式的余数
特殊情况：
    幂指数为奇数时求余需要再乘底数再求模
    如：7^13 = (7^6)^2*7; ->多乘一个7
*/

#include<stdio.h>
int x,n,m,sum;
void init()
{
	printf("请输入x的n次幂：");
	scanf("%d%d",&x,&n);
	printf("请输入模：");
	scanf("%d",&m);
}
int function(int x,int n,int m)
{
    if(n==1)
    {
        return x%m;
    }
    sum=function(x,n/2,m);                      //递归一直到为1时结束
    if(n%2==1)                                  //奇数
    {
        sum=(sum*sum*x)%m;
    }
    else
    {
        sum=(sum*sum)%m;
    }
    return sum;
}
int main()
{
	init();
    function(x,n,m);
    printf("%d 的 %d 次幂模 %d 的余数为：%d\n",x,n,m,sum);
    return 0;
} 
