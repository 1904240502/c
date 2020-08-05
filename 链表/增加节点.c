//增加指定节点
#include<stdio.h>
#include<malloc.h>
struct stu
{
    int n;
    struct stu *next;
};
typedef struct stu STU;

STU *create();
STU *add(STU *head,int n);
void display(STU *head);

int main()
{
    STU *p;
    int n;
    p=create();
    printf("请输入要增加的节点：");
    scanf("%d",&n);
    p=add(p,n);
    display(p);
    return 0;
}

STU *create()
{
    STU *head,*tail,*pnew;
    head=(STU *)malloc(sizeof(STU));
    head->next=NULL;
    tail=head;

    while(1)
    {
        pnew=(STU *)malloc(sizeof(STU));
        scanf("%d",&pnew->n);
        pnew->next=NULL;
        if(pnew->n==-1)
        {
            break;
        }
    
        tail->next=pnew;
        tail=pnew;
    }
    return head;
}
STU *add(STU *head,int n)
{
    int i=1;
    STU *phead,*tail,*pnew;
    phead=(STU *)malloc(sizeof(STU));
    phead->next=NULL;
    tail=phead;

    phead=head;
    tail=phead->next;

    while(i<=n)                                                       //i的数与tail的数相对应
    {
        if(i==n)                                                      //增加pnew
        {
            pnew=(STU *)malloc(sizeof(STU));                          //新增节点赋值
            printf("请输入节点的数据：");
            scanf("%d",&pnew->n);
            pnew->next=NULL;

            phead->next=pnew;
            pnew->next=tail;
        }

        phead=phead->next;
        tail=phead->next;
        i++;
    }
    return head;
}
void display(STU *head)
{
    while(head->next!=NULL)
    {
        head=head->next;
        printf("%d ",head->n);
    }
    printf("\n");
}
