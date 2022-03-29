#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode* lchild,*rchild;
}BSTNode,*BSTree;
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
//递归算法简单，但执行效率较低，递归实现留给大家编写
BSTNode *BST_Search(BSTree T,KeyType key,BSTree &p)
{
    p=NULL;//存储要找的结点的父亲
    while(T!=NULL&&key!=T->key)
    {
        p=T;
        if(key<T->key)
            T=T->lchild;
        else
            T=T->rchild;
    }
    return T;
}
BSTNode *BST_Search2(BSTree T,KeyType key,BSTree &p)
{
    if(T->key==key)
    {
        p=T;
        return T;
    }else if(T->key<key)
    {
        return BST_Search2(T->rchild,key,p);
    }else
    {
        return BST_Search2(T->lchild,key,p);
    }
}
//这个书上没有二叉排序树删除代码--考大题没那么高
void DeleteNode(BSTree &root,KeyType x)
{
    BSTree temNode;
    if(root==NULL)
    {
        return;
    }
    if(root->key>x)
    {
        DeleteNode(root->lchild,x);   
    }else if(root->key>x)
    {
        DeleteNode(root->lchild,x);
    }else{//查找到了删除节点
        if(root->lchild==NULL)
        {
            temNode=root;
            root=root->rchild;
            free(temNode);
        }else if(root->rchild==NULL)
        {
            temNode=root;
            root=root->lchild;
            free(temNode);
        }else{
            temNode=root->lchild;
            while(temNode->rchild!=NULL)
            {
                temNode=temNode->rchild;
            }
            root->key=temNode->key;
            DeleteNode(root->lchild,temNode->key);
        }
    }  
}
void InOrder(BSTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lchild);
		printf("%3d",T->key);
		InOrder(T->rchild);
	}
}
//二叉排序树的创建，中序遍历，查找，删除
int main()
{
	BSTree T=NULL;//树根
	BSTree parent;//存储父亲结点的地址值
	BSTree search;
    BSTree p;
	KeyType str[7]={54,20,66,40,28,79,58};//将要进入二叉排序树的元素值
	Create_BST(T,str,7);
	InOrder(T);
	printf("\n");
	search=BST_Search(T,40,parent);
	if(search)
	{
		printf("Find it, value=%d\n",search->key);
	}else{
		printf("Not find\n");//没找到search返回的是NULL
	}
    BST_Search2(T,28,p);
    printf("Find it %d\n",p->key);
	DeleteNode(T,54);//删除某个结点
	InOrder(T);
	printf("\n");
	//system("pause");
}