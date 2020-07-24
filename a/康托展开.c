/* 
   X=a[n] (n?1)!+a[n-1](n?2)!+?+a[1]?0!
   在5个数的排列组合中，计算 34152的康托展开值。
   首位是3，则小于3的数有两个，为1和2，a[5]=2，则首位小于3的所有排列组合为a[5]*4!
   第二位是4，由于第一位小于4，1、2、3中一定会有1个充当第一位，所以排在4之下的只剩2个，所以其实计算的是在第二位之后小于4的个数。因此a[4]=2。
   第三位是1，则在其之后小于1的数有0个，所以a[3]=0。
   第四位是5，则在其之后小于5的数有1个，为2，所以a[2]=1。
   最后一位就不用计算啦，因为在它之后已经没有数了，所以固定为0
   根据公式：
           x=2*4!+2*3!+0+1*1!+0*0!=61
　 所以比34152小的组合有61个，即34152是排第62。*/
#include<stdio.h>
//求阶乘
int factorial_function(int num)
{
	if(num <= 1)
		return 1;
	else
		return (factorial_function(num-1)*num);
}

int main()
{
        int i=0,j;
        int count=0,k;
        int sum=0;
        char num[10];
        printf("请输入数字：");
        scanf("%s",num);
        while(num[i]!=NULL)
        {
                i++;
                count++;               //数字的长度

        }
        for(i=0;i<count;i++)
        {
                k=0;                  //a[n]的个数
                for(j=i+1;j<count;j++)
                {
                        if(num[i]>num[j])
                        {
                                k++;
                        }
                }
                sum+=k*factorial_function(count-(i+1));        //i+1为所减个数
        }
        printf("%s是第%d位",num,sum+1);
        getchar();
        return 0;
}