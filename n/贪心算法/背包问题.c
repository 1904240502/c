#include<stdio.h>

void knapsack(int n,float m,float v[],float w[],float x[])
{
    int i;
    float c=m;
    for(i=1;i<=n;i++)
    {
        x[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(w[i]>c)
        {
            break;
        }
        x[i]=1;
        c-=w[i];
    }
    if(i<=n)
    {
        x[i]=c/w[i];
    }
}

int main()
{
    float v[]={0,60,100,120};
    float w[]={0,10,20,30};
    int n=3;
    float m=50;
    float x[3];
    int i;
    knapsack(n,m,v,w,x);
    printf("装入背包的物品为：");
    for(i=1;i<=n;i++)
    {
        printf("%f   ",x[i]);
    }
    return 0;
}