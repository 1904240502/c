/*
  ���� 11 3           
  ��� 3 6 9 1 5 10 4 11 8 2 7
  ��1����̭���ǵ�3��ͬѧ����2����̭���ǵ�6��ͬѧ
  ������ǰ�˳����̭��ͬѧ���
*/
#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;
    printf("������ͬѧ�����뱻��̭�����֣�");
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