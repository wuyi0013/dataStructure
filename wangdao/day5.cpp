#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,* LinkList;
//头插法新建链表
LinkList listHeadInsert(LinkList &L)
{
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999)
    {
        LinkList s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
//尾插法新建链表
LinkList listTailInsert(LinkList &L)
{
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    LinkList r=L;
    while(x!=9999)
    {
        LinkList s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=r->next;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    return L;
}
//打印链表
void printList(LinkList L)
{
    for(L=L->next;L!=NULL;L=L->next)
    {
        printf("%3d",L->data);
    }
    printf("\n");
}
//查找第几个结点的值
LinkList getElem(LinkList L,int i)
{
    int j=1;
    LinkList p=L->next;
    if (0 == i)
	{
		return L;//i是零就返回头结点
	}
	if (i < 1)
	{
		return NULL;//i是负值就返回空
	}
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
//按值查找
LinkList locateElem(LinkList L, ElemType i)
{
    LinkList p;
    for(p=L->next;p!=NULL;p=p->next)
    {
        if(p->data==i)
            return p;
    }
    return NULL; 
}
//往第i个位置插入元素
bool ListFrontInsert(LinkList L, int i, ElemType e)
{
    LinkList p=getElem(L,i-1);
    if (NULL == p)
	{
		return false;
	}
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//删除第i个位置的元素
bool ListDelete(LinkList L, int i)
{
    LinkList p=getElem(L,i-1);
    if (NULL == p)
	{
		return false;
	}
    LinkList q=p->next;
    if (NULL == q)
	{
		return false;
	}
    p->next=q->next;
    free(q);
    q=NULL;
    return true;
}
int main()
{
    LinkList L;
    //listHeadInsert(L);
    listTailInsert(L);
    printList(L);
    LinkList search=getElem(L,2);
    if(search!=NULL)
	{
		//printf("Successfully find\n");
		printf("%d\n",search->data);
	}
    ListFrontInsert(L,2,99);
    printList(L);
    ListDelete(L,4);
    printList(L);
    return 0;
}