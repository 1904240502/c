/*
  �����ң����������ڵ�����Ԫ�ؽ��бȽϣ����ϴ�ķŵ�����
  �磺2 6 5 3 1
    6>5  6,5����  6>3  6,3���� 6>1 6,1����  2 5 3 1 6
    5>3  5,3����  5>1  5,1����              2 3 1 5 6
    3>1  3,1����                            2 1 3 5 6
    2>1  2,1����                            1 2 3 5 6
*/
//��С����
#include<stdio.h>
void exchange(int a[],int n);
int main()
{
    int i,n;
    printf("������Ԫ�ظ�����");
    scanf("%d",&n);
    int a[n];
    printf("������Ԫ�أ�");
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
    int i,j;
    int temp;
    for(i=1;i<n;i++)                               //��ѭ������
    {
        for(j=0;j<n-i;j++)                         //ÿ�δӵ�һ����ʼ�������Ƚϣ��������Ѿ�����õ�  ���Ե�  Ԫ�ظ���-�Ѿ�ѭ������ ����
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}