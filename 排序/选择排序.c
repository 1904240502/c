/*
  �ӵ�һ��λ�ÿ�ʼ�Ƚϣ��ҳ���С�ģ��͵�һ��λ�û�������ʼ��һ��
  �磺
    2 6 5 3 1    ||    2 6 5 3 1
       2>1 2,1����                �����1 6 5 3 2      
    6 5 3 2  ||  6 5 3 2
       6>5 6,5����  5>3 5,3���� 3>2 3,2����    �����1 2 6 5 3
    6 5 3   ||  6 5 3
       6>5 6,5����  5>3 5,3����      �����1 2 3 6 5
    6 5   ||   6 5
       6>5 6,5����     �����1 2 3 5 6
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
    for(i=0;i<n-1;i++)                         //λ����i��Ԫ����λ����j�ıȽ�     
    {
        for(j=i;j<n;j++)                       //ǰ������Ѿ�����õ�  ���Դ�i��ʼ  
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}