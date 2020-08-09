/*
  输入：10
       1 7 5 10 13 15 10 5 16 8
  输出：7
  假设开始相等无摇摆  即start=begin x=1然后
  1——7上升 即start=up  x=2      7——5下降 即start=down   x=3        5——10上升 即start=up  x=4
  10——13上升无变化              13——15上升无变化                    5——10下降 即start=down  x=5
  10——5下降无变化               5——16上升 即start=up  x=6           16——8下降 即start=down  x=7          
*/
#include<stdio.h>
int main()
{
    int i,n;
    printf("请输入元素个数：");
    scanf("%d",&n);
    int a[n];
    printf("请输入人数：");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);                       
    }
    int begin=0,up=1,down=-1;
    int x=1;                               //个数从第2个数开始
    int start=begin;
    for(i=1;i<n;i++)
    {
        switch(start)
        {
            case 0:
            if(a[i-1]<a[i])
            {
                start=up;
                x++;
            }
            else if(a[i-1]>a[i])
            {
                start=down;
                x++;
            };
            break;
            case 1:
            if(a[i-1]>a[i])
            {
                start=down;
                x++;
            }
            break;
            case -1:
            if(a[i-1]<a[i])
            {
                start=up;
                x++;
            }
            break;
        }
    }
    printf("最长摇摆子序列个数为%d",x);
    return 0;
}