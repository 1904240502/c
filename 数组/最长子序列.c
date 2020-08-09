/*
   输入 9
       -2 1 -3 4 -1 2 1 -5 4
   输出 6 【4 -1 2 1】
*/
#include<stdio.h>
int maxSubArray(int* a, int n)
{
    int sum,t,i;
    sum=t=a[0];
    for(i=1;i<n;i++)
    {
        t+=a[i];
        if(sum<t)
        {
            sum = t;
        }
        if(t<0) 
        {
            t=0;
        }
    }      
    return sum;
}
int main()
{
	int n,a[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    printf("%d\n",maxSubArray(a,n));
	return 0;
}