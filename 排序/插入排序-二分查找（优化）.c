//���뵽����λ��
/*
  �ӵڶ���λ�ÿ�ʼ�Ƚϲ��룬�ҳ�С�ģ���ǰ�潻����ֱ��û�б���С��,���λ�þ��ǲ���λ��
  �磺2 6 5 3 1
    2         ||  6
       b=0 e=1 mid=0 2<6 b=1 ����ڶ���λ��i=1  �����2 6 5 3 1     
    2 6       ||  5
       b=0 e=2 mid =1 6>5 e=1 mid=0 2<5 b=1 ����ڶ���λ��i=1, 6,5����      �����2 5 6 3 1
    2 5 6     ||  3
       b=0 e=3 mid =1 5>3 e=1 mid=0 2<3 b=1 ����ڶ���λ��i=1, 6,3����  5,3����      �����2 3 5 6 1
    2 3 5 6   ||  1
       b=0 e=4 mid =2 5>1 e=2 mid=1 3>1 e=1 mid=0 2>1 e=0 �����һ��λ��i=0  6,1����  5>1 5,1����  3>1 3,1����  2>1 2,1����  �����1 2 3 5 6
*/
//��С����
#include<stdio.h>
void exchange(int a[],int n);
int change(int a[],int n, int m);
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
    int i,j,x;
    int temp;
    for(i=1;i<n;i++)                         //�ӵڶ�����ʼ�����һ������   
    {
        x=change(a,i,a[i]);
        for(j=i;j>x;j--)                    //�Һ���λ��
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}
int change(int a[],int n, int m)
{
    int begin,end,mid;
    end=n;
    begin=0;
    
    while(end>begin)                          //����ҿ�[begin,end) begin==endʱ�ǲ���λ��
    {
        mid=(end+begin)/2;
       
        if(a[mid]>m)
        {
            end=mid;
        }
        else 
        {
            begin=mid+1;                      //������ڵĻ�Ҫ�����λ����mid��
        }
    } 
    return begin;
}