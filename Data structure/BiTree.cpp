#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct LinkNode
{
    BiTNode *data;
    struct LinkNode *next;  
}LinkNode;
typedef struct
{
    LinkNode *rear,*front;
}LinkQueue;
//初始化队列(带头节点)
void InitQueue(LinkQueue &q)
{
    q.front=q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    q.front->next=NULL;//初始时rear和front都指向头节点
}
//入队(带头节点)
bool EnQueue(LinkQueue &q,BiTNode *x)
{
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    q.rear->next=s;
    q.rear=s;
    return true;
}
//出队(带头节点)
bool DeQueue(LinkQueue &q,BiTNode *&x)
{
    if(q.front==q.rear)
    return false;
    LinkNode *s=q.front->next;
    x=s->data;
    q.front->next=s->next;
    if(q.rear==s)
        q.rear=q.front;
    free(s);
    return true;    
}
//判断队列是否为空
bool EmptyQueue(LinkQueue q)
{
    if(q.front==q.rear)
        return true;
    else
        return false;    
}
//先序创建二叉树
void CreateBiTree(BiTree &T)
{
    char ch;
    ch=getchar();
    if(ch=='#')
        T=NULL;
    else
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//先序遍历二叉树
void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        printf("%c->",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历二叉树
void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        printf("%c->",T->data);
        InOrder(T->rchild);
    }
}
//后序遍历二叉树
void PosOrder(BiTree T)
{
    if(T!=NULL)
    {
        PosOrder(T->lchild);       
        PosOrder(T->rchild);
        printf("%c->",T->data);
    }
}
//层序遍历
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!EmptyQueue(Q))
    {
        DeQueue(Q,p);
        printf("%c->",p->data);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}
//求树的深度
int TreeDepth(BiTree T)
{
    if(T==NULL)
        return 0;
    else
    {
        int l=TreeDepth(T->lchild);
        int r=TreeDepth(T->rchild);
        return l>r?l+1:r+1;
    }
}

int main()
{
    BiTree T;
    printf("Please Input your data:\n");
    CreateBiTree(T);
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PosOrder(T);
    printf("\n");
    printf("%d\n",TreeDepth(T));
    LevelOrder(T);
    printf("\n");
    system("pause");
    return 0;
}