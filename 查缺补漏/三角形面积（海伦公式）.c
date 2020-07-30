#include<stdio.h>
#include<math.h>
void main()
{
    double a,b,c;                        //三边
    double p;                            //半周长
    double s;                            //面积
    printf("请输入三边长度：");
    scanf("%lf%lf%lf",&a,&b,&c);
    p=(a+b+c)/2;
    s=pow((p*(p-a)*(p-b)*(p-c)),0.5);
    printf("三角形面积为%.2lf",s);
}