/*
�������� ( 1 ~ 100): 1
�������� ( 1 ~ 100): 3

�����һά�����Ԫ��:
����Ԫ�� a11: 1
����Ԫ�� a12: 2
����Ԫ�� a13: 3
����ڶ�ά�����Ԫ��:
����Ԫ�� a11: 1
����Ԫ�� a12: 2
����Ԫ�� a13: 3

��ά������ӽ��:

2   4   6
*/
#include <stdio.h>
 
int main(){
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
 
    printf("�������� ( 1 ~ 100): ");
    scanf("%d", &r);
    printf("�������� ( 1 ~ 100): ");
    scanf("%d", &c);
 
    printf("\n�����һά�����Ԫ��:\n");
 
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            printf("����Ԫ�� a%d%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
 
    printf("����ڶ�ά�����Ԫ��:\n");
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            printf("����Ԫ�� a%d%d: ",i+1, j+1);
            scanf("%d", &b[i][j]);
        }
 
    // ���
 
    for(i=0;i<r;++i)
        for(j=0;j<c;++j)
        {
            sum[i][j]=a[i][j]+b[i][j];
        }
 
    // ��ʾ���
    printf("\n��ά������ӽ��: \n\n");
 
    for(i=0;i<r;++i)
        for(j=0;j<c;++j)
        {
 
            printf("%d   ",sum[i][j]);
 
            if(j==c-1)
            {
                printf("\n\n");
            }
        }
    
    return 0;
}