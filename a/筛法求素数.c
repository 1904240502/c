//�ж�һ��������n�Ƿ�Ϊ�����������ж����Ƿ���Ա�2��n-1֮��������������Ƿ���Ա�2��sqr(n) ֮�����������
#include<stdio.h>
#include<math.h>
int main()
{
    int n;         //ɸѡ��Χ
    int i,j;
    int flag;      //�ж��Ƿ�Ϊ����  0������ 1����
    printf("������ɸѡ��Χ��");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        flag=1;          //ÿ����һ��Ҫ��flag��ԭ
        if(i==1)
        {
            flag=0;
        }
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("%d������\n",i);
        }
    }
    

}