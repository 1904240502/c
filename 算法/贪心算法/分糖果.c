/*
   ĳ�����ӿ����ø�С���ǹ����㣬��û��Ҫ�ø�����ǹ����㣬�������������������
*/
#include<stdio.h>
void exchange(int a[],int n);
int num(int a[],int b[],int n);
int main()
{
    int i,n;
    printf("������Ԫ�ظ�����");
    scanf("%d",&n);
    int a[n],b[n];
    printf("������������");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);                       //��
    }
    printf("�������ǹ�����");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);                       //�ǹ�
    }
    exchange(a,n);
    exchange(b,n);
    n=num(a,b,n);
    printf("����������%d��",n);

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
int num(int a[],int b[],int n)           //b[i]>=a[j]���� �ǹ���>����
{
    int i,j;
    int x=0,y=0;                         //x:��¼���������� y:��¼�ϴ���������������λ��ʹ�´η������һ����ʼ
    for(i=0;i<n;i++)                     //�ǹ�
    {
        for(j=y;j<n;j++)                 //��
        {
            if(b[i]>=a[j])
            {
                x++;
                y=j+1;
                break;
            }
        }
    }
    return x;
}