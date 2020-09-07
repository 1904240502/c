//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
//���ݽṹ
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;                             //LinkList=LNode *
//��������
int menu_select(); 
void  CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList &L,int i, ElemType &e);
Status  ListInsert_L(LinkList &L,int i,ElemType e);
Status ListDelete_L(LinkList &L,int i,ElemType &e);
int LocateElem_L(LinkList L,ElemType e);

//������
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
			printf("������Ԫ�صĸ���:");
			scanf("%d",&n);			
			CreateList_L(L,n);
			printf("�������\n");
			break;
		case 2:		
			PrintList_L(L);
			break;
		 case 3:
			printf("���ò��Һ�������֪λ����Ԫ�أ�\n");
			printf("������Ҫ���ҵ�λ��:");
			scanf("%d",&n);
			if(GetElem_L(L,n,e))
			{
				printf("Ԫ���Ѿ��ҵ�������ȡ�ɹ���\n");
			}
			else
			{
				printf("û�и�λ��\n");
			}
			break;
		 case 4:
			printf("���ò��뺯��\n");
			printf("������Ҫ�����λ��:");
			scanf("%d",&n);
			if(ListInsert_L(L,n,e))
			{
				printf("Ԫ���Ѿ����룡\n");
			}
			else
			{
				printf("û�и�λ��\n");
			}
			break;
		 case 5:
			printf("����ɾ������\n");
			printf("������Ҫɾ����λ��:");
			scanf("%d",&n);
			if(ListDelete_L(L,n,e))
			{
				printf("Ԫ���Ѿ����룡\n");
			}
			else
			{
				printf("û�и�λ��\n");
			}
			break;
		case 6:printf("���ò��Һ�������֪Ԫ����λ��\n");
			printf("��һ���߼�λ��Ϊ%d\n",LocateElem_L(L,e));
			break;			
		case 0:
			printf("���������ллʹ�ã�\n\n");
			exit(0);
		}
	}
	return 0;
}

int menu_select()
{
	int sn;
	printf("\n��ʾ�˵�\n");
	printf("1.����\n");
	printf("2.��ʾ\n");
	printf("3.ȡԪ��\n");
	printf("4.����\n");
	printf("5.ɾ��\n");
	printf("6.����\n");
	printf("0.�˳�\n");
	printf("���� 0-6:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>6)
			printf("\n���������ѡ0��6��");
		else
			break;
	}
	return sn;
}
//����������ͷ�巨����֪���Ա�ĳ���
void CreateList_L(LinkList &L,int n)
{
	LinkList p;
	int i;	
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	printf("����������%d��Ԫ��:\n",n);
	for(i=n;i>=1;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);	//��ʽ�����ַ���������
		p->next=L->next;                            //ʹp������L����
		L->next=p;                                  //ʹp����L
	}
}
//���������
void PrintList_L(LinkList L)
{
	LinkList p;
	p=L->next;
	printf("��������е�Ԫ��:\n");
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
//ȡԪ�غ���
Status GetElem_L(LinkList &L,int i, ElemType &e)
//LΪ��ͷ���ĵ������ͷָ��
//����i��Ԫ�ش���ʱ����ֵ��ֵ��e������ok,���򷵻�ERROR,
{
	int j=1;
	LinkList p;
	p=L->next;
	while(p&&j<i)                      //pΪ�ջ�pָ��iʱ����ѭ��
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)                          //j���Դ���i��
	{
		return ERROR;
	}
	e=p->data;                          //ȡֵ
	return OK;
} 
//���뺯��  
Status  ListInsert_L(LinkList &L,int i,ElemType e)
//�ڴ�ͷ�ڵ�ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
{
	int j=1;
	LinkList p,S;
	p=L->next;
	while(j<i-1&&p)                     //Ѱ��i��ǰһ�����
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return ERROR;
	}
	S=(LinkList)malloc(sizeof(LNode));  //�����½�㸳ֵ
	S->data=e;
	S->next=p->next;                    //����
	p->next=S;
    return OK;
} 
//ɾ������  
Status ListDelete_L(LinkList &L,int i,ElemType &e)
//�ڴ�ͷ�ڵ�ĵ������Ա�L��,ɾ����i��Ԫ�أ�����e������ֵ
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
	q=p->next;                        //ɾ�����
	e=q->data;
	p->next=q->next;                 //q��¼ָ���򣬼���free()����������ָ����һ���ͷ�
	free(q);
	return OK;
} 
//ȡԪ��  
int LocateElem_L(LinkList L,ElemType e)
//�ҵ������߼�λ��,δ�ҵ�����0
//�ҵ�L�е�һ����e��ȵ�Ԫ��
{
	int i=1;
    LinkList p;
	p=L->next;
	while(p&&p->data!=e)                   //�ҵ���pΪ������ѭ��
	{
		p=p->next;
		i++;                              //��¼λ��
	}
	if(!p)
	{
		return 0;
	}
    return i;
}   
