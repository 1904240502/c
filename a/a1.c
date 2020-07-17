//辗转相除法
#include<stdio.h>
int main()
{
    int a,b,c;      //除数，被除数，余数
    printf("Please input:");
    scanf("%d %d",&a,&b);
    c=a%b;
    while(c!=0)
    {
        a=b;
		b=c;
		c=a%b;
    }
    printf("you answer:%d",b);
}