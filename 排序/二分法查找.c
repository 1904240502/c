#include<stdio.h>
int exchange(int a[],int n,int m);
int main()
{
    int i,n,m,x;
    printf("请输入元素个数：");
    scanf("%d",&n);
    int a[n];
    printf("请输入元素：");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("请输入要查找元素：");
    scanf("%d",&m);
    x=exchange(a,n,m);
    if(x==-1)
    {
        printf("没有查找到");
    }
    else
    {
        printf("%d在第%d位",m,x+1);
    }
    
    return 0;
}
int exchange(int a[],int n,int m)
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
        else if(a[mid]<m)
        {
            begin=mid;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
