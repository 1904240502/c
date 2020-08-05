/*
输入：                                   
1 5 9 做饭
2 1 4 看电视
3 5 7 看书
4 3 5 玩电脑
5 3 8 做作业
6 8 11 出门
7 0 6 跑步
8 6 10 购物
9 12 14 上课
10 8 12 学习
11 2 13 打篮球
0
输出：
2 1 4 看电视
3 5 7 看书
6 8 11 出门
9 12 14 上课
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct activityarrangement
{
    int n;                                   //参加活动人数
    int begin;                               //开始时间
    int end;                                 //结束时间
    char name[20];                           //活动名称
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

LIST *create()                                                                     //创建链表
{
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;
    
    printf("活动序号 开始时间 结束时间 活动名称\n");
    while(1)
    {
        pnew=(LIST *)malloc(sizeof(LIST));                                        //创建节点 
        scanf("%d",&pnew->x.n);      
        if(pnew->x.n==0)                                                          //终止循环
        {
            break;
        } 
          
        scanf("%d%d%s\n",&pnew->x.begin,&pnew->x.end,pnew->x.name);
        pnew->next=NULL;

        tail->next=pnew;                                                         //将节点链接在链表
        tail=pnew;
    }

    return head;
}
LIST *exchange(LIST *list)                                                         //排序（开始时间）
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
        n++;                                                                     //统计总共活动个数
        head=head->next;
    }
    for(i=1;i<n;i++)                                                             //选择排序法(外循环进行n-1次)
    {
        head=list;                                                               //记录要交换节点的前一个节点   即第一个节点：head
        pnew=head->next;                                                         //要交换的第一个节点     即第二个节点：pnew
        tail=pnew->next;                                                         //要交换的第二个节点     即第三个节点：tail
        for(j=i;j<n&&pnew->next!=NULL;j++)                                       //内循环进行n-1-i次(特殊链表结束也终止)
        {
            if(pnew->x.end>tail->x.end)                                      //链表节点交换
            {
                head->next=tail;                                                 //第一个的尾巴接第三个的头
                pnew->next=tail->next;                                           //第二个的尾巴接第四个的头
                tail->next=pnew;                                                 //第三个的尾巴接第二个的头                                                               
            }
            head=head->next;
            pnew=head->next;
            tail=pnew->next;
        }
    }
    return list;
}
void display(LIST *list)                                                           //显示链表
{
    printf("活动序号 开始时间 结束时间 活动名称\n");
    while(list->next!=NULL)
    {
        list=list->next;                                                         //节点转向下一个
        printf("   %d        %d        %d      %s\n",list->x.n,list->x.begin,list->x.end,list->x.name);
    }
}
LIST *choose(LIST *list)                                                           //贪心算法进行筛选
{
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;

    head=list;
    pnew=head->next;                                                                //第一个节点必选(贪心)时间开始最早活动安排越多
    tail=pnew->next;                                                                //从第二个节点(tail)进行筛选(pnew:当前要筛选节点的前一个节点)
    while(pnew->next!=NULL)                                                         
    {
        if(pnew->x.end>tail->x.begin)                                               //是否选中活动的结束时间小于这一个的开始时间(成立的话这个活动可以安排)
        {
            pnew=delete(pnew);
        }
        else
        {
            pnew=pnew->next;
        }
        tail=tail->next;                                                            //改变tail的地址否则上面判断的tail一直不变还是初始赋的值(114行)
    }
    return head;
}
LIST *delete(LIST *list)                                                           //删除节点  
{
    LIST *head,*tail,*pnew;
    head=(LIST *)malloc(sizeof(LIST));
    head->next=NULL;
    tail=head;
    head=list;
    pnew=head->next;                                                               //要删除节点
    tail=pnew->next;

    head->next=tail;
    return head;
}