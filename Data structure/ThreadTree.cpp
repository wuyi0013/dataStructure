#include <stdio.h>
#include <stdlib.h>
typedef struct ThreadNode{
    char data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
ThreadTree pre=NULL;
//先序建立二叉树
void CreatTree(ThreadTree &T)
{
    char ch;
    ch=getchar();
    if(ch=='#')
    {
        T==NULL;
    }
    else
    {
        T=(ThreadTree)malloc(sizeof(ThreadNode));
        T->data=ch;
        T->ltag=0;
        T->rtag=0;
        CreatTree(T->lchild);
        CreatTree(T->rchild);
    }
}
//中序遍历二叉树，一边遍历一遍线索化
void InThread(ThreadTree &T,ThreadTree &pre)
{
    if(T!=NULL)
    {
        InThread(T->lchild,pre);
        if(T->lchild==NULL)
        {
            T->lchild=pre;
            T->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL)
        {
            pre->rchild=T;
            pre->rtag=1;
        }
        pre=T;
        InThread(T->rchild,pre);
    }
}
//中序线索化二叉树
void CreatThread(ThreadTree &T)
{
    pre=NULL;
    if(T!=NULL)
    {
        InThread(T,pre);
        if(pre->rchild==NULL)
            pre->rtag=1;
    }
}
//找到以p为根的子树中，第一个被中序遍历的节点
ThreadNode *FirstNode(ThreadNode *p)
{
    while(p->ltag==0)
        p=p->lchild;
    return p;
}
//在中序线索二叉树中找到节点p的后继节点
ThreadNode *NextNode(ThreadNode *p)
{
    if(p->rtag==0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}
//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void InOrder(ThreadNode *T)
{
    for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
        printf("%c->",p->data);
}
int main()
{
    ThreadTree T;
    CreatTree(T);
    CreatThread(T);
    InOrder(T);
    system("pause");
    return 0;
}







