#include<stdio.h>
#include<math.h>
void main()
{
    double a,b,c;                        //����
    double p;                            //���ܳ�
    double s;                            //���
    printf("���������߳��ȣ�");
    scanf("%lf%lf%lf",&a,&b,&c);
    p=(a+b+c)/2;
    s=pow((p*(p-a)*(p-b)*(p-c)),0.5);
    printf("���������Ϊ%.2lf",s);
}