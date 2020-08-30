#include<stdio.h>

#include<math.h>

#define MIN(x,y) (x<y?x:y)

#define MAX(x,y) (x>y?x:y)

typedef struct{

double x,y;

}Point;

double mindistance(Point p1,Point p2,Point q)

{

int flag=1;

double k;

Point s;

//һ���������ֻ��Ҫ����㣨s�����㣨q���ľ��뼴��

if(p1.x==p2.x)//��x�ᴹֱ

{

s.x=p1.x;

s.y=q.y;

flag=0;

}

if(p1.y==p2.y)//��y�ᴹֱ

{

s.x=q.x;

s.y=p1.y;

flag=0;

}

//ֱ�߼�����x�ᴹֱ��Ҳ����y�ᴹֱ

if(flag)

{

k=(p2.y-p1.y)/(p2.x-p1.x);//����ֱ��б��

s.x=(k*k*p1.x+k*(q.y-p1.y)+q.x)/(k*k+1);

s.y=k*(s.x-p1.x)+p1.y;

}

if(MIN(p1.x,p2.x)<=s.x && s.x<=MAX(p1.x,p2.x))

return sqrt((q.x-s.x)*(q.x-s.x)+(q.y-s.y)*(q.y-s.y));//�������빫ʽ���������߶�֮��

else

return MIN(sqrt((q.x-p1.x)*(q.x-p1.x)+(q.y-p1.y)*(q.y-p1.y)),sqrt((q.x-p2.x)*(q.x-p2.x)+(q.y-p2.y)*(q.y-p2.y)));

}

int main(void)

{

Point p1,p2,q;

double x,y;

scanf("%lf%lf",&x,&y);

p1.x=x;

p1.y=y;

scanf("%lf%lf",&x,&y);

p2.x=x;

p2.y=y;

scanf("%lf%lf",&x,&y);

q.x=x;

q.y=y;

printf("�����ľ���Ϊ%lf\n",mindistance(p1,p2,q));

return 0;

}

