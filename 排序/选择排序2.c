/*
  �ӵ�һ��λ�ÿ�ʼ�Ƚϣ��ҳ���С�ģ��͵�һ��λ�û�������ʼ��һ��
  �磺
    2 6 5 3 1    i=min=0 
    ��i+1��ʼ�����İ����Ƚ��ҵ���Сֵ���±� min=4 �ٽ�i��min����                �����1 6 5 3 2      
    1 6 5 3 2    i=min=1
    ��i+1��ʼ�����İ����Ƚ��ҵ���Сֵ���±� min=4 �ٽ�i��min����                �����1 2 5 3 6 
    1 2 5 3 6    i=min=2
    ��i+1��ʼ�����İ����Ƚ��ҵ���Сֵ���±� min=3 �ٽ�i��min����                �����1 2 3 5 6 
    1 2 3 5 6    i=min=3
    ��i+1��ʼ�����İ����Ƚ��ҵ���Сֵ���±� min=3 �ٽ�i��min����                �����1 2 3 5 6
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
    int temp,min;
    for(i=0;i<n-1;i++)                         //��ѭ������    
    {
        min=i;                                 //��¼��С�±�
        for(j=i+1;j<n;j++)                     
        {
            if(a[min]>a[j])                    //��С���±��ҳ�
            {
                min=j;                         
            }
        }
        temp=a[i];                             //�ٻ�����ǰ��
        a[i]=a[min];
        a[min]=temp;
    }
}