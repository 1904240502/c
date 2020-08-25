/*
  从第一个位置开始比较，找出最小的，和第一个位置互换，开始下一轮
  如：
    2 6 5 3 1    i=min=0 
    从i+1开始与后面的挨个比较找到最小值的下标 min=4 再将i与min交换                结果：1 6 5 3 2      
    1 6 5 3 2    i=min=1
    从i+1开始与后面的挨个比较找到最小值的下标 min=4 再将i与min交换                结果：1 2 5 3 6 
    1 2 5 3 6    i=min=2
    从i+1开始与后面的挨个比较找到最小值的下标 min=3 再将i与min交换                结果：1 2 3 5 6 
    1 2 3 5 6    i=min=3
    从i+1开始与后面的挨个比较找到最小值的下标 min=3 再将i与min交换                结果：1 2 3 5 6
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
    int temp,min;
    for(i=0;i<n-1;i++)                         //外循环次数    
    {
        min=i;                                 //记录最小下标
        for(j=i+1;j<n;j++)                     
        {
            if(a[min]>a[j])                    //将小的下标找出
            {
                min=j;                         
            }
        }
        temp=a[i];                             //再换到最前面
        a[i]=a[min];
        a[min]=temp;
    }
}