//判断一个正整数n是否为素数，可以判断它是否可以被2到n-1之间的数整除，即是否可以被2到sqr(n) 之间的数整除。
#include<stdio.h>
#include<math.h>
int main()
{
    int n;         //筛选范围
    int i,j;
    int flag;      //判断是否为素数  0：不是 1：是
    printf("请输入筛选范围：");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        flag=1;          //每经历一边要将flag还原
        if(i==1)
        {
            flag=0;
        }
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("%d是素数\n",i);
        }
    }
    

}