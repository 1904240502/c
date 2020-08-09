/*
   输入 5
        1 2 0 5 8
   输出  1 2 5 8
        4
*/
#include<stdio.h>
void  CompactIntegers(int a[],int x); 
int main()
{
    int n,i;
    scanf("%d",&n);
    int array[n];     //定义一个n个元素的数组   
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    CompactIntegers(array,n);
    return 0;
}
void  CompactIntegers(int a[],int x)
{
    int i,cnt=0;
    for(i=0;i<x;i++)
        if(a[i])        //元素为1的数组才输出并且计数变量加1； 
        { 
            printf("%d ",a[i]);
            cnt++; 
        }
    printf("\n%d\n",cnt);    
}