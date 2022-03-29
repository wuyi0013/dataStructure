#include <stdio.h>//
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
//初始化单链表
bool Initlist(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //带头节点
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}
//销毁单链表
void DestoryList(LinkList &L)
{
    LNode *p;
    L = L->next;
    while (L->next != NULL)
    {
        p = L;
        L = L->next;
        free(p);
    }
    free(L);
}
//判断是否是空单链表
bool Empty(LinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}
//在第i个位置上插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *s;
    LNode *p = L;
    int j = 0;
    while (j < i - 1 && p != NULL)
    {
        L = L->next;
        j++;
    }
    if (p == NULL)
        return false;
    s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = e;
    return true;
}
//指定节点的后插操作
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = e;
    return true;
}
//前插操作,在指定节点p之前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
    if (p = NULL)
        return false;
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
//按位序删除，删除第i个元素并返回其值
bool DeleteList(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
        return false;
    LNode *s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}
//按位查找，返回第i个节点
LNode *GetElem(LinkList &L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//按值查找
LNode *LocateElem(LinkList &L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}
//求表长
int length(LinkList &L)
{
    LNode *p = L;
    int j = 0;
    while (p->next != NULL)
    {
        p = p->next;
        j++;
    }
    return j;
}
//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int j;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s;
    LNode *r = L;
    scanf("%d", &j);
    while (j != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = j;
        r->next = s;
        r = s;
        scanf("%d", &j);
    }
    r->next = NULL;
    return L;
}
//头插法建立新链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int j;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &j);
    while (j != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = j;
        s->next = L->next;
        L->next = s;
        scanf("%d", &j);
    }
    return L;
}
//输出单链表
void PrintList(LinkList L)
{
    L=L->next;
    while(L->next!=NULL)
    {
        printf("%d ",L->data);
        L=L->next;
    }
    printf("%d\n",L->data);
}
//删除表中所有值大于mink且小于maxk的元素
LinkList delete_range_list(LinkList &L,int mink,int maxk)
{
    LNode *p;
    LNode *r;
    LNode *q;
    q=L;
    while(q->next->data<=mink)
    {
        q=q->next;
    }
    r=q;
    q=q->next;
    while(q->data<maxk)
    {
        p=q;
        q=q->next;
        free(p);
    }
    r->next=q;
    return L;
}
/*int main()
{
    int e;
    LinkList L;
    Initlist(L);
    List_TailInsert(L);
    PrintList(L);
    scanf("%d",&e);
    printf("%p",LocateElem(L,e));
    DestoryList(L);
    system("pause");
    return 0;
}*/
//删除表中所有值大于mink且小于maxk的元素
int main()
{
    int j,k;
    LinkList L;
    Initlist(L);
    List_TailInsert(L);
    PrintList(L);
    printf("Input the range that you want to delete:\n");
    scanf("%d%d",&j,&k);
    delete_range_list(L,j,k); 
    PrintList(L);
    DestoryList(L);
    system("pause");
    return 0;
}