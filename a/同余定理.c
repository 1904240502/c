#include<stdio.h>
#define Max 100
int num[Max];//*********************�洢������
int val[Max];//*********************�洢��������ֵ
int n,i;
 
void init(int num[],int * n)
{
	int i = 0;
	printf("������Ԫ�صĸ�����");
	scanf("%d",n);                   //��ָ�븳ֵ
	for(i=0;i<*n;i++)                 
	{
		printf("�������%d��Ԫ�أ�",i+1);
		scanf("%d",&num[i]);
	}
}
//շת��������������
int qiuYushu(int a,int b)
{
	int r = a % b;
	if(r==0)
		return b;
	else
		return qiuYushu(b,r);
}
 
void function(int num[],int n)
{
	int i = 0,j = 0,k = 0;
	for(i=0;i<n-1;i++)                       //n��������ѭ����Ҫn-1������Ϊ��0��ʼ����<
	{
		for(j=i+1;j<n;j++)
		{
			val[k] = num[i] - num[j];
			if(val[k]>0)                     //ȷ����ֵΪ��
				val[k] = val[k];
			else
				val[k] = 0 - val[k];
			k++;
		}
	}
	//��val[0]��val[1]�����Լ����Ȼ���ٶ�t��val[i](i>=2)�����Լ����һֱ�����һ�����ó�val�����е����Լ����Ϊ����
	int t = qiuYushu(val[0],val[1]);
	for(i=2;i<n;i++)
	{
		t = qiuYushu(val[i],t);
	}
	printf("%d����%d������������\n",t,n);
}

int main()
{
	init(num,&n);                    //����n���ݵ�ַ�����������������n��ֵ��,�����������n����ʧ
 
	function(num,n);
 
	return 0;
}
/*���븳ֵ��ֱ�ӱ��ȫ�ֱ���
     ԭ��                                               ����
  init(num,&n); .......................................init();
  void init(int num[],int * n).........................void init()*/