#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
typedef struct BiTNode{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
typedef struct tag{
    BiTree p;
    struct tag *pnext;
}tag_t,*ptag_t;
//队列相关的数据结构
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode* next;
}LinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;
//递归实现
//abdhiejcfg

//栈的相关数据结构
#define MaxSize 50
typedef BiTree ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &S)
{
	S.top=-1;
}

bool StackEmpty(SqStack &S)
{
	if(S.top==-1)
		return true;
	else
		return false;
}
//入栈
bool Push(SqStack &S,ElemType x)
{
	if(S.top==MaxSize-1)
	{
		return false;
	}
	S.data[++S.top]=x;
	return true;
}
//出栈
bool Pop(SqStack &S,ElemType &x)
{
	if(-1==S.top)
		return false;
	x=S.data[S.top--];
	return true;
}
//读取栈顶元素
bool GetTop(SqStack &S,ElemType &x)
{
	if(-1==S.top)
		return false;
	x=S.data[S.top];
	return true;
}
//带头结点的队列
void InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue &Q,ElemType x)
{
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	s->data=x;s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}

bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if(Q.front==Q.rear) return false;
	LinkNode *p=Q.front->next;//头结点什么都没存，所以头结点的下一个节点才有数据
	x=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return true;
}
//前序遍历
void preOrder(BiTree p)
{
	if(p!=NULL)
	{
		putchar(p->data);//等价于visit函数
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//中序遍历
void inOrder(BiTree p)
{
    if(p!=NULL)
    {
        inOrder(p->lchild);
        putchar(p->data);
        inOrder(p->rchild);
    }
}
//后序遍历
void postOrder(BiTree p)
{
    if(p!=NULL)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        putchar(p->data);
    }
}
//中序遍历非递归
void inOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p||!StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }else{
            Pop(S,p);
            putchar(p->data);
            p=p->rchild;
        }
    }
}
//层序遍历
void levelOrder(BiTree T)
{
    LinkQueue q;
    InitQueue(q);
    EnQueue(q,T);
    BiTree p;
    while(!IsEmpty(q))
    {
        DeQueue(q,p);
        putchar(p->data);
        if(p->lchild!=NULL) //入队左孩子
			EnQueue(q,p->lchild);
		if(p->rchild!=NULL)  //入队右孩子
			EnQueue(q,p->rchild);
    }
}
int main()
{
    BiTree pnew;
    int i,j,pos;
    char c;
    BiTree tree=NULL;//树根
    ptag_t phead=NULL,ptail=NULL,listpnew,pcur;//phead就是队列头，ptail就是队列尾
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')
        {
            break;
        }
        pnew=(BiTree)calloc(1,sizeof(BiTNode));
        pnew->data=c;
        listpnew=(ptag_t)calloc(1,sizeof(tag_t));
        listpnew->p=pnew;
        if(NULL==tree)
        {
            tree=pnew;
            phead=listpnew;
            ptail=listpnew;
            pcur=listpnew;
            continue;
        }else{
            ptail->pnext=listpnew;
            ptail=listpnew;
        }
        if(pcur->p->lchild==NULL)
        {
            pcur->p->lchild=pnew;
        }else if(pcur->p->rchild==NULL)
        {
            pcur->p->rchild=pnew;
            pcur=pcur->pnext;
        }
    }
    printf("--------preOrder----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
	preOrder(tree);
	printf("\n--------inOrder------------\n");//先打印左孩子，打印父亲，打印右孩子
	inOrder(tree);
	printf("\n--------postOrder------------\n");//先打印左孩子，打印右孩子，最后打印父亲
	postOrder(tree);
	printf("\n--------InOrder2------\n");//重要性低
	inOrder2(tree); 
	printf("\n--------levelTraversal-----------\n");
	levelOrder(tree);
	printf("\n");
	//system("pause");
    return 0;
}