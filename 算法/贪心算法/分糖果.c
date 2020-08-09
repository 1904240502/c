/*
   某个孩子可以用更小的糖果满足，则没必要用更大的糖果满足，保留大的满足需求更大的
   排序前
   人数：5 10 2 9 15   糖果：6 1 20 3 8
   排序后
   人数：2 5 9 10 15   糖果：1 3 6 8 20
   糖果1(i)不满足分配
   糖果3(i)满足人数2(j)及以后分配  因为2已经被使用j需要从下一个开始
   糖果6(i)满足人数5(j)及以后分配  因为5已经被使用j需要从下一个开始
   糖果8(i)不满足分配
   糖果20(i)满足人数9(j)及以后分配  
   所以最大满足为3
*/
#include<stdio.h>
void exchange(int a[],int n);
int num(int a[],int b[],int n);
int main()
{
    int i,n;
    printf("请输入元素个数：");
    scanf("%d",&n);
    int a[n],b[n];
    printf("请输入人数：");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);                       //人
    }
    printf("请输入糖果数：");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);                       //糖果
    }
    exchange(a,n);
    exchange(b,n);
    n=num(a,b,n);
    printf("最大可以满足%d个",n);

    return 0;
}
void exchange(int a[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)                               //外循环次数
    {
        for(j=0;j<n-i;j++)                         //每次从第一个开始，两两比较，后面是已经排序好的  所以到  元素个数-已尽循环次数 结束
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int num(int a[],int b[],int n)           //b[i]>=a[j]满足 糖果数>人数
{
    int i,j;
    int x=0,y=0;                         //x:记录满足分配个数 y:记录上次满足分配的人数的位置使下次分配从下一个开始
    for(i=0;i<n;i++)                     //糖果
    {
        for(j=y;j<n;j++)                 //人
        {
            if(b[i]>=a[j])
            {
                x++;
                y=j+1;
                break;
            }
        }
    }
    return x;
}