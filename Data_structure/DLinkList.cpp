#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;
//双向链表头插法
DLinkList Dlist_head_insert(DLinkList &DL)
{
    int x;
    DL=(DLinkList)malloc(sizeof(DNode));
    DL->next=NULL;
    DL->prior=NULL;
    scanf("%d",&x);
    while(x!=9999)
    {
        DLinkList s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;
        s->next=DL->next;
        if(DL->next!=NULL)
        {
            DL->next->prior=s;
        }
        s->prior=DL;
        DL->next=s;
        scanf("%d",&x);
    }
    return DL;
}
//双向链表尾插法
DLinkList Dlist_tail_insert(DLinkList &DL)
{
    int x;
    DL=(DLinkList)malloc(sizeof(DNode));
    DL->next=NULL;
    DL->prior=NULL;
    scanf("%d",&x);
    DLinkList r=DL;
    while(x!=9999)
    {
        DLinkList s=(DLinkList)malloc(sizeof(DNode));
        s->data=x;
        s->next=r->next;
        s->prior=r;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    return DL;
}
//按序号查找结点值
DNode *getElem(DLinkList DL,int i)
{
    DLinkList p=DL->next;
    int j=1;
    if(i==0)
		return DL;
	if(i<1)
		return NULL;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
//新结点插入第i个位置
bool DListFrontInsert(DLinkList &DL,int i,ElemType e)
{
    DLinkList p=getElem(DL,i-1);
    if(NULL==p)
	{
		return false;
	}
    DLinkList s=(DLinkList)malloc(sizeof(DNode));
    s->data=e;
    s->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return true;
}
//删除第i个结点
bool DListDelete(DLinkList DL,int i)
{
    DLinkList p=getElem(DL,i-1);
    if(NULL==p)
	{
		return false;
	}
    DLinkList q=p->next;
    if(q==NULL)
    {
        return false;
    }
    p->next=q->next;//断链
	if(q->next!=NULL)//q->next为NULL删除的是最后一个结点
	{
		q->next->prior=p;
	}
	free(q);
    q=NULL;
    return true;
}
//链表打印
void printDList(DLinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}
int main()
{
    DLinkList DL;
    //Dlist_head_insert(DL);
    Dlist_tail_insert(DL);
    printDList(DL);
    DLinkList search=getElem(DL,2);
	if(search!=NULL)
	{
		printf("Successfully find\n");
		printf("%d\n",search->data);
	}
	DListFrontInsert(DL,3,99);
	printDList(DL);
	DListDelete(DL,2);
	printDList(DL);
    return 0;
}