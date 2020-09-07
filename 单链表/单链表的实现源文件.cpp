//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
//数据结构
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;                             //LinkList=LNode *
//函数声明
int menu_select(); 
void  CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList &L,int i, ElemType &e);
Status  ListInsert_L(LinkList &L,int i,ElemType e);
Status ListDelete_L(LinkList &L,int i,ElemType &e);
int LocateElem_L(LinkList L,ElemType e);

//主函数
int main()
{	
	LinkList L;
	int n;
	ElemType e;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			printf("请输入元素的个数:");
			scanf("%d",&n);			
			CreateList_L(L,n);
			printf("创建完成\n");
			break;
		case 2:		
			PrintList_L(L);
			break;
		 case 3:
			printf("调用查找函数（已知位序找元素）\n");
			printf("请输入要查找的位序:");
			scanf("%d",&n);
			if(GetElem_L(L,n,e))
			{
				printf("元素已经找到，并获取成功！\n");
			}
			else
			{
				printf("没有该位序\n");
			}
			break;
		 case 4:
			printf("调用插入函数\n");
			printf("请输入要插入的位序:");
			scanf("%d",&n);
			if(ListInsert_L(L,n,e))
			{
				printf("元素已经插入！\n");
			}
			else
			{
				printf("没有该位序\n");
			}
			break;
		 case 5:
			printf("调用删除函数\n");
			printf("请输入要删除的位序:");
			scanf("%d",&n);
			if(ListDelete_L(L,n,e))
			{
				printf("元素已经插入！\n");
			}
			else
			{
				printf("没有该位序\n");
			}
			break;
		case 6:printf("调用查找函数（已知元素找位序）\n");
			printf("第一个逻辑位序为%d\n",LocateElem_L(L,e));
			break;			
		case 0:
			printf("程序结束，谢谢使用！\n\n");
			exit(0);
		}
	}
	return 0;
}

int menu_select()
{
	int sn;
	printf("\n显示菜单\n");
	printf("1.创建\n");
	printf("2.显示\n");
	printf("3.取元素\n");
	printf("4.插入\n");
	printf("5.删除\n");
	printf("6.查找\n");
	printf("0.退出\n");
	printf("输入 0-6:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>6)
			printf("\n输入错误，重选0－6：");
		else
			break;
	}
	return sn;
}
//创建单链表，头插法，已知线性表的长度
void CreateList_L(LinkList &L,int n)
{
	LinkList p;
	int i;	
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	printf("请逆序输入%d个元素:\n",n);
	for(i=n;i>=1;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);	//格式输入字符串补出来
		p->next=L->next;                            //使p连接起L后面
		L->next=p;                                  //使p连接L
	}
}
//输出单链表
void PrintList_L(LinkList L)
{
	LinkList p;
	p=L->next;
	printf("输出链表中的元素:\n");
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
//取元素函数
Status GetElem_L(LinkList &L,int i, ElemType &e)
//L为带头结点的单链表的头指针
//当第i个元素存在时，其值赋值给e并返回ok,否则返回ERROR,
{
	int j=1;
	LinkList p;
	p=L->next;
	while(p&&j<i)                      //p为空或p指向i时跳出循环
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)                          //j可以大于i吗？
	{
		return ERROR;
	}
	e=p->data;                          //取值
	return OK;
} 
//插入函数  
Status  ListInsert_L(LinkList &L,int i,ElemType e)
//在带头节点的单链线性表L中第i个位置之前插入元素e
{
	int j=1;
	LinkList p,S;
	p=L->next;
	while(j<i-1&&p)                     //寻找i的前一个结点
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return ERROR;
	}
	S=(LinkList)malloc(sizeof(LNode));  //创建新结点赋值
	S->data=e;
	S->next=p->next;                    //连接
	p->next=S;
    return OK;
} 
//删除函数  
Status ListDelete_L(LinkList &L,int i,ElemType &e)
//在带头节点的单链线性表L中,删除第i个元素，并由e返回其值
{
	int j=1;
	LinkList p,q;
	p=L->next;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return ERROR;
	}
	q=p->next;                        //删除结点
	e=q->data;
	p->next=q->next;                 //q记录指针域，假若free()了数据域与指针域一起释放
	free(q);
	return OK;
} 
//取元素  
int LocateElem_L(LinkList L,ElemType e)
//找到返回逻辑位序,未找到返回0
//找到L中第一个与e相等的元素
{
	int i=1;
    LinkList p;
	p=L->next;
	while(p&&p->data!=e)                   //找到或p为空跳出循环
	{
		p=p->next;
		i++;                              //记录位序
	}
	if(!p)
	{
		return 0;
	}
    return i;
}   
