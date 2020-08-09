/*
输入：
5                                         5
1 2 2 5 4                                 1 2 2 5 4
2                                         0
输出：
index = 1                                 Not found
*/
#include <stdio.h>
#define MAXN 10

int search( int list[], int n, int x );

int main()
{
    int i, index, n, x;
    int a[MAXN];

    scanf("%d", &n);
    for( i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    index = search( a, n, x );
    if( index != -1 )
    {
        printf("index = %d\n", index);
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}

int search( int list[], int n, int x )
{
    int i;
    for(i=0;i<n;i++)
    {
        if(x==list[i])
        {
            return i;
        }
    }
    if(i==n)
    {
        return -1;
    }
}
