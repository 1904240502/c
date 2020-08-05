//将节点 1->2->3->4   转换为 2->1->4->3
#include<stdio.h>
#include<malloc.h>
struct stu
{
    int n;
    struct stu *next;
};
typedef struct stu STU;

STU *create();
STU *exchange(STU *head);
void display(STU *head);

int main()
{
    STU *p;
    p=create();
    p=exchange(p);
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
STU *exchange(STU *head)
{
    STU *phead,*tail,*pnew;
    phead=(STU *)malloc(sizeof(STU));
    phead->next=NULL;
    tail=phead;

    phead=head;
    while(phead->next!=NULL&&phead->next->next!=NULL)
    {
        pnew=phead->next;
        tail=pnew->next;

        phead->next=tail;
        pnew->next=tail->next;
        tail->next=pnew;

        phead=phead->next->next;
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
