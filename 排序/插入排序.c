//插入到合适位置
/*
  从第二个位置开始比较插入，找出小的，和前面交换，直到没有比它小的,这个位置就是插入位置
  如：2 6 5 3 1
    2         ||  6
       结果：2 6 5 3 1     
    2 6       ||  5
       6>5 6,5交换      结果：2 5 6 3 1
    2 5 6     ||  3
       6>3 6,3交换  5>3 5,3交换      结果：2 3 5 6 1
    2 3 5 6   ||  1
       6>1 6,1交换  5>1 5,1交换  3>1 3,1交换  2>1 2,1交换  结果：1 2 3 5 6
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
    for(i=1;i<n;i++)                         //从第二个开始，最后一个结束   
    {
        for(j=i;j>=0;j--)                    //找合适位置
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}