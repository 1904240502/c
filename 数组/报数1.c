/*
  输入 11 3           
  输出 3 6 9 1 5 10 4 11 8 2 7
  第1个淘汰的是第3个同学，第2个淘汰的是第6个同学
  输出的是按顺序淘汰的同学编号
*/
#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;
    printf("请输入同学总数与被淘汰的数字：");
    scanf("%d %d", &n, &m);
    CountOff( n, m, out );   
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}

void CountOff( int n, int m, int out[] )
{
    int i,j=0;
    int x=0;
    int num[MAXN];
    for(i=0;i<n;i++)
        num[i]=i+1;
    i=0;
    while(j<n)
    {
        if(num[i]!=0)
            x++;
        if(x==m)
        {
            x=0;
            out[j]=num[i];
            j++;
            num[i]=0;
        }
        i++;
        if(i==n)
            i=0;
    }
}