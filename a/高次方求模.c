/*
��ʽ��
    x%n=(x1%n * x2%n * x3%n* x4%n* x5%n)%n
    x=x1x2x3x4x5
ȡֵ���������У�
    A%b=(a*a)%b=(a%b*a%b)%b
    ���޽�������������ָ������2��,ֱ��������ָ��Ϊ1ʱֹͣ��ʱ��������֮�����������ԭʽ������
���������
    ��ָ��Ϊ����ʱ������Ҫ�ٳ˵�������ģ
    �磺7^13 = (7^6)^2*7; ->���һ��7
*/

#include<stdio.h>
int x,n,m,sum;
void init()
{
	printf("������x��n���ݣ�");
	scanf("%d%d",&x,&n);
	printf("������ģ��");
	scanf("%d",&m);
}
int function(int x,int n,int m)
{
    if(n==1)
    {
        return x%m;
    }
    sum=function(x,n/2,m);                      //�ݹ�һֱ��Ϊ1ʱ����
    if(n%2==1)                                  //����
    {
        sum=(sum*sum*x)%m;
    }
    else
    {
        sum=(sum*sum)%m;
    }
    return sum;
}
int main()
{
	init();
    function(x,n,m);
    printf("%d �� %d ����ģ %d ������Ϊ��%d\n",x,n,m,sum);
    return 0;
} 
