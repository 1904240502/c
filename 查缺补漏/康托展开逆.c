#include<stdio.h>
//��׳�
int factorial_function(int num)
{
	if(num <= 1)
		return 1;
	else
		return (factorial_function(num-1)*num);
}
//��������(��С����)
char *sort_function(char num[],int count)
{
    int i,j;
    int temp;
    for(i=0;i<count-1;i++)               //count��������ѭ����Ҫcount-1������Ϊ��0��ʼ����<
    {
        for(j=0;j<count-1-i;j++)         //��ѭ�����count-1��
        {
            if(num[j]>num[j+1])         //������Ԫ�رȽ������򽻻�
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    return num;
}
//����ɾ��(ѡ���ɾ��)
char *delete_function(char num[],int n,int count)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(i>=n)
        {
            num[i]=num[i+1];
        }
    }
    return num;
}
int main()
{
    int i=0;
    int count=0,k;                       //λ����a[n]:����С�ĸ���
    int sum1,sum2;                       //ȫ�����λ��
    char num1[10],num2[10];              //����
    printf("���������֣�");
    scanf("%s",num1);
    while(num1[i]!=NULL)
    {
        i++;
        count++;                         //���ֵĳ���

    }
    *sort_function(num1,count),     
    printf("������λ����");
    scanf("%d",&sum1);
    sum2=sum1;
    sum1-=1;
    for(i=0;i<count;i++)
    {
        k=sum1/factorial_function(count-(i+1));
        sum1%=factorial_function(count-(i+1));
        num2[i]=num1[k];
        *delete_function(num1,k,count);
    }
    printf("��%d������%s",sum2,num2);
    return 0;
}
/* 
   num1="35412"   num1="12345"   sum1=62
   62-1=61                       sum2=61                        sum1=62        
   61/4!=2...13                  k=2:����ȫ���е�3λ��num1[2]     sum1=13    num2[0]=3    num1="1245"
   13/3!=2...1                   k=2:����ȫ���е�3λ��num1[2]     sum1=1     num2[1]=4    num1="125"
   1/2!=0...1                    k=0:����ȫ���е�1λ��num1[0]     sum1=1     num2[2]=1    num1="25"
   1/1!=1...0                    k=1:����ȫ���е�2λ��num1[1]     sum1=0     num2[3]=5    num1="2"
   0/0!=0...0                    k=0:����ȫ���е�1λ��num1[0]     sum1=0     num2[4]=2    num1=""
*/
