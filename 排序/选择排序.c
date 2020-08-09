/*
  从第一个位置开始比较，找出最小的，和第一个位置互换，开始下一轮
  如：
    2 6 5 3 1    ||    2 6 5 3 1
       2>1 2,1交换                结果：1 6 5 3 2      
    6 5 3 2  ||  6 5 3 2
       6>5 6,5交换  5>3 5,3交换 3>2 3,2交换    结果：1 2 6 5 3
    6 5 3   ||  6 5 3
       6>5 6,5交换  5>3 5,3交换      结果：1 2 3 6 5
    6 5   ||   6 5
       6>5 6,5交换     结果：1 2 3 5 6
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
    for(i=0;i<n-1;i++)                         //位置在i的元素与位置在j的比较     
    {
        for(j=i;j<n;j++)                       //前面的是已经排序好的  所以从i开始  
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}