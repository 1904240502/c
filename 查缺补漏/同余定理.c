#include<stdio.h>
#define Max 100
int num[Max];//*********************存储被除数
int val[Max];//*********************存储被除数差值
int n,i;
 
void init(int num[],int * n)
{
	int i = 0;
	printf("请输入元素的个数：");
	scanf("%d",n);                   //给指针赋值
	for(i=0;i<*n;i++)                 
	{
		printf("请输入第%d个元素：",i+1);
		scanf("%d",&num[i]);
	}
}
//辗转相除法求最大公因数
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
	for(i=0;i<n-1;i++)                       //n个数则外循环需要n-1次又因为从0开始所以<
	{
		for(j=i+1;j<n;j++)
		{
			val[k] = num[i] - num[j];
			if(val[k]>0)                     //确保差值为正
				val[k] = val[k];
			else
				val[k] = 0 - val[k];
			k++;
		}
	}
	//求val[0]和val[1]求最大公约数，然后再对t和val[i](i>=2)求最大公约数，一直到最后一个，得出val数组中的最大公约数即为所求！
	int t = qiuYushu(val[0],val[1]);
	for(i=2;i<n;i++)
	{
		t = qiuYushu(val[i],t);
	}
	printf("%d是这%d个数的最大除数\n",t,n);
}

int main()
{
	init(num,&n);                    //这里n传递地址，否则在这个函数中n赋值后,出了这个函数n会消失
 
	function(num,n);
 
	return 0;
}
/*若想赋值后直接变成全局变量
     原来                                               现在
  init(num,&n); .......................................init();
  void init(int num[],int * n).........................void init()*/