/*
    6 2
输入：   1 2 3 4 5 6
输出：   5 6 1 2 3 4
*/
#include <stdio.h>
#define MAXN 10

int ArrayShift( int a[], int n, int m );             //a[]传递数组的地址 int a[] = int *a直接return 0就可以若想return a则需指针数组int * ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) 
    {
        scanf("%d", &a[i]);
    }
    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) 
    {
        if (i != 0) 
        {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

int ArrayShift( int a[], int n, int m )
{
    int i,j;
    int temp;
    for(i=1;i<=m;i++)
    {
        temp=a[n-1];
        for(j=n-1;j>=0;j--)
        {
            a[j]=a[j-1];
        }
        a[0]=temp;
    }
    return 0;
}