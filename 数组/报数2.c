/*
  ���� 11 3
  ��� 4 10 1 7 5 2 11 9 3 6 8 
  ��1��ͬѧ����4����̭����2��ͬѧ���ڸ���̭
  �������ÿ��ͬѧ��̭��˳��
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
    int b[n];
 
    for(int i=0; i<n; i++)
        b[i]=i+1;
 
    int i=0, j=0, idx=0;
    while(1)
    {
        if(b[i]!=0) j++;
        if(j==m)
        {
            out[i]=++idx;
            b[i]=j=0;
        }
        i++;
 
        if(i>=n) i=0;
        if(idx==n) break;
    }
}

