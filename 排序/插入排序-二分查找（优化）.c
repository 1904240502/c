//插入到合适位置
/*
  从第二个位置开始比较插入，找出小的，和前面交换，直到没有比它小的,这个位置就是插入位置
  如：2 6 5 3 1
    2         ||  6
       b=0 e=1 mid=0 2<6 b=1 插入第二个位置i=1  结果：2 6 5 3 1     
    2 6       ||  5
       b=0 e=2 mid =1 6>5 e=1 mid=0 2<5 b=1 插入第二个位置i=1, 6,5交换      结果：2 5 6 3 1
    2 5 6     ||  3
       b=0 e=3 mid =1 5>3 e=1 mid=0 2<3 b=1 插入第二个位置i=1, 6,3交换  5,3交换      结果：2 3 5 6 1
    2 3 5 6   ||  1
       b=0 e=4 mid =2 5>1 e=2 mid=1 3>1 e=1 mid=0 2>1 e=0 插入第一个位置i=0  6,1交换  5>1 5,1交换  3>1 3,1交换  2>1 2,1交换  结果：1 2 3 5 6
*/
//从小到大
#include<stdio.h>
void exchange(int a[],int n);
int change(int a[],int n, int m);
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
    int i,j,x;
    int temp;
    for(i=1;i<n;i++)                         //从第二个开始，最后一个结束   
    {
        x=change(a,i,a[i]);
        for(j=i;j>x;j--)                    //找合适位置
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}
int change(int a[],int n, int m)
{
    int begin,end,mid;
    end=n;
    begin=0;
    
    while(end>begin)                          //左闭右开[begin,end) begin==end时是查找位置
    {
        mid=(end+begin)/2;
       
        if(a[mid]>m)
        {
            end=mid;
        }
        else 
        {
            begin=mid+1;                      //如果等于的话要插入的位置在mid后
        }
    } 
    return begin;
}