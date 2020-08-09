/*
   某个孩子可以用更小的糖果满足，则没必要用更大的糖果满足，保留大的满足需求更大的
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