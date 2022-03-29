#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode* lchild,*rchild;
}BSTNode,*BSTree;
//栈的相关数据结构
#define MaxSize 50
typedef BSTree ElemType;
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
int BST_Insert(BSTree &T,KeyType k)
{
    if(T==NULL)
    {
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }else if(k==T->key)
    {
        return 0;
    }else if(k<T->key)
    {
        return BST_Insert(T->lchild,k);
    }else
    {
        return BST_Insert(T->rchild,k);
    }
}
//创建二叉排序树
void Create_BST(BSTree &T,KeyType str[],int n)
{
    T=NULL;
    int i=0;
    while(i<n)
    {
        BST_Insert(T,str[i]);
        i++;
    }
}

void InOrder(BSTree T,KeyType* seq,int &i)
{
	SqStack S;
    InitStack(S);
    BSTree p=T;
    while(p||!StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }else{
            Pop(S,p);
            //printf("%3d",p->key);
            seq[i++]=p->key;
            p=p->rchild;
        }
    }
}

//二叉排序树的创建，中序遍历，查找，删除
int main()
{
	BSTree T=NULL;//树根
	KeyType str[10]={};//将要进入二叉排序树的元素值
    for(int i=0;i<10;i++)
    {
        scanf("%d",&str[i]);
    }
	Create_BST(T,str,10);
    KeyType seq[10];
    int i=0;
	InOrder(T,seq,i);
	//printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("%3d",seq[i]);
    }
    printf("\n");
	int low=0;
    int high=9;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(seq[mid]==21)
        {
            printf("%d",mid);
            break;
        }else if(seq[mid]<21)
        {
            low=mid+1;
        }else{
            high=mid-1;
        }
        
        
    }
    return 0;
    
}