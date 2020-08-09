/*
  从左到右，数组中相邻的两个元素进行比较，将较大的放到后面
  如：2 6 5 3 1
    6>5  6,5交换  6>3  6,3交换 6>1 6,1交换  2 5 3 1 6
    5>3  5,3交换  5>1  5,1交换              2 3 1 5 6
    3>1  3,1交换                            2 1 3 5 6
    2>1  2,1交换                            1 2 3 5 6
*/
//从小到大
#include<stdio.h>
void exchange(int a[],int n);
int main()
{
    int i,n;
    printf("请输入元素个数：");
    scanf("%d",&n);
    int a[n];
    printf("请输入元素：");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    exchange(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
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