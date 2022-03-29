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
        printf("%3d ",L->data);
    }
    printf("\n");
}
int main()
{
    LinkList L;
    listHeadInsert(L);
    printList(L);
    LinkList P;
    listTailInsert(P);
    printList(P);
    return 0;
}