/*
  ���룺10
       1 7 5 10 13 15 10 5 16 8
  �����7
  ���迪ʼ�����ҡ��  ��start=begin x=1Ȼ��
  1����7���� ��start=up  x=2      7����5�½� ��start=down   x=3        5����10���� ��start=up  x=4
  10����13�����ޱ仯              13����15�����ޱ仯                    5����10�½� ��start=down  x=5
  10����5�½��ޱ仯               5����16���� ��start=up  x=6           16����8�½� ��start=down  x=7          
*/
#include<stdio.h>
int main()
{
    int i,n;
    printf("������Ԫ�ظ�����");
    scanf("%d",&n);
    int a[n];
    printf("������������");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);                       
    }
    int begin=0,up=1,down=-1;
    int x=1;                               //�����ӵ�2������ʼ
    int start=begin;
    for(i=1;i<n;i++)
    {
        switch(start)
        {
            case 0:
            if(a[i-1]<a[i])
            {
                start=up;
                x++;
            }
            else if(a[i-1]>a[i])
            {
                start=down;
                x++;
            };
            break;
            case 1:
            if(a[i-1]>a[i])
            {
                start=down;
                x++;
            }
            break;
            case -1:
            if(a[i-1]<a[i])
            {
                start=up;
                x++;
            }
            break;
        }
    }
    printf("�ҡ�������и���Ϊ%d",x);
    return 0;
}