/*
���룺                                   
1 5 9 ����
2 1 4 ������
3 5 7 ����
4 3 5 �����
5 3 8 ����ҵ
6 8 11 ����
7 0 6 �ܲ�
8 6 10 ����
9 12 14 �Ͽ�
10 8 12 ѧϰ
11 2 13 ������
0
�����
2 1 4 ������
3 5 7 ����
6 8 11 ����
9 12 14 �Ͽ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct activityarrangement
{
    int n;                                   //�μӻ����
    int begin;                               //��ʼʱ��
    int end;                                 //����ʱ��
    char name[20];                           //�����
};
struct list
{
    struct activityarrangement x;
    struct list *next;
};
typedef struct list LIST;

LIST *create();
LIST *delete(LIST *list);
LIST *exchange(LIST *list);
void display(LIST *list);
LIST *choose(LIST *list);
LIST *delete(LIST *list);

int main()
{
    LIST *list;
    list=create();
    list=exchange(list);
    list=choose(list);
    display(list);
    return 0;
}

LIST *create()                                                                     //��������
{
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;
    
    printf("���� ��ʼʱ�� ����ʱ�� �����\n");
    while(1)
    {
        pnew=(LIST *)malloc(sizeof(LIST));                                        //�����ڵ� 
        scanf("%d",&pnew->x.n);      
        if(pnew->x.n==0)                                                          //��ֹѭ��
        {
            break;
        } 
          
        scanf("%d%d%s\n",&pnew->x.begin,&pnew->x.end,pnew->x.name);
        pnew->next=NULL;

        tail->next=pnew;                                                         //���ڵ�����������
        tail=pnew;
    }

    return head;
}
LIST *exchange(LIST *list)                                                         //���򣨿�ʼʱ�䣩
{
    int i,j;
    int n=0;
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;
    pnew=head;
    
    head=list;
    while(head->next!=NULL)
    {
        n++;                                                                     //ͳ���ܹ������
        head=head->next;
    }
    for(i=1;i<n;i++)                                                             //ѡ������(��ѭ������n-1��)
    {
        head=list;                                                               //��¼Ҫ�����ڵ��ǰһ���ڵ�   ����һ���ڵ㣺head
        pnew=head->next;                                                         //Ҫ�����ĵ�һ���ڵ�     ���ڶ����ڵ㣺pnew
        tail=pnew->next;                                                         //Ҫ�����ĵڶ����ڵ�     ���������ڵ㣺tail
        for(j=i;j<n&&pnew->next!=NULL;j++)                                       //��ѭ������n-1-i��(�����������Ҳ��ֹ)
        {
            if(pnew->x.end>tail->x.end)                                      //����ڵ㽻��
            {
                head->next=tail;                                                 //��һ����β�ͽӵ�������ͷ
                pnew->next=tail->next;                                           //�ڶ�����β�ͽӵ��ĸ���ͷ
                tail->next=pnew;                                                 //��������β�ͽӵڶ�����ͷ                                                               
            }
            head=head->next;
            pnew=head->next;
            tail=pnew->next;
        }
    }
    return list;
}
void display(LIST *list)                                                           //��ʾ����
{
    printf("���� ��ʼʱ�� ����ʱ�� �����\n");
    while(list->next!=NULL)
    {
        list=list->next;                                                         //�ڵ�ת����һ��
        printf("   %d        %d        %d      %s\n",list->x.n,list->x.begin,list->x.end,list->x.name);
    }
}
LIST *choose(LIST *list)                                                           //̰���㷨����ɸѡ
{
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;

    head=list;
    pnew=head->next;                                                                //��һ���ڵ��ѡ(̰��)ʱ�俪ʼ��������Խ��
    tail=pnew->next;                                                                //�ӵڶ����ڵ�(tail)����ɸѡ(pnew:��ǰҪɸѡ�ڵ��ǰһ���ڵ�)
    while(pnew->next!=NULL)                                                         
    {
        if(pnew->x.end>tail->x.begin)                                               //�Ƿ�ѡ�л�Ľ���ʱ��С����һ���Ŀ�ʼʱ��(�����Ļ��������԰���)
        {
            pnew=delete(pnew);
        }
        else
        {
            pnew=pnew->next;
        }
        tail=tail->next;                                                            //�ı�tail�ĵ�ַ���������жϵ�tailһֱ���仹�ǳ�ʼ����ֵ(114��)
    }
    return head;
}
LIST *delete(LIST *list)                                                           //ɾ���ڵ�  
{
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;
    head=list;
    pnew=head->next;                                                               //Ҫɾ���ڵ�
    tail=pnew->next;

    head->next=tail;
    return head;
}