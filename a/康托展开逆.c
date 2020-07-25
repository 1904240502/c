#include<stdio.h>
//求阶乘
int factorial_function(int num)
{
	if(num <= 1)
		return 1;
	else
		return (factorial_function(num-1)*num);
}
//数组排序(从小到大)
char *sort_function(char num[],int count)
{
    int i,j;
    int temp;
    for(i=0;i<count-1;i++)               //count个数则外循环需要count-1次又因为从0开始所以<
    {
        for(j=0;j<count-1-i;j++)         //内循环最多count-1次
        {
            if(num[j]>num[j+1])         //相邻两元素比较逆序则交换
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    return num;
}
//数组删除(选择后删除)
char *delete_function(char num[],int n,int count)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(i>=n)
        {
            num[i]=num[i+1];
        }
    }
    return num;
}
int main()
{
    int i=0;
    int count=0,k;                       //位数，a[n]:比其小的个数
    int sum1,sum2;                       //全排序的位数
    char num1[10],num2[10];              //数字
    printf("请输入数字：");
    scanf("%s",num1);
    while(num1[i]!=NULL)
    {
        i++;
        count++;                         //数字的长度

    }
    *sort_function(num1,count),     
    printf("请输入位数：");
    scanf("%d",&sum1);
    sum2=sum1;
    sum1-=1;
    for(i=0;i<count;i++)
    {
        k=sum1/factorial_function(count-(i+1));
        sum1%=factorial_function(count-(i+1));
        num2[i]=num1[k];
        *delete_function(num1,k,count);
    }
    printf("第%d的数是%s",sum2,num2);
    return 0;
}
/* 
   num1="35412"   num1="12345"   sum1=62
   62-1=61                       sum2=61                        sum1=62        
   61/4!=2...13                  k=2:数字全排列第3位即num1[2]     sum1=13    num2[0]=3    num1="1245"
   13/3!=2...1                   k=2:数字全排列第3位即num1[2]     sum1=1     num2[1]=4    num1="125"
   1/2!=0...1                    k=0:数字全排列第1位即num1[0]     sum1=1     num2[2]=1    num1="25"
   1/1!=1...0                    k=1:数字全排列第2位即num1[1]     sum1=0     num2[3]=5    num1="2"
   0/0!=0...0                    k=0:数字全排列第1位即num1[0]     sum1=0     num2[4]=2    num1=""
*/
