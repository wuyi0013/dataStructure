#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
//在二叉排序树中找到值为key的节点
BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)
    {
        if (T->key < key)
            T = T->rchild;
        else
            T = T->lchild;
    }
    return T;
}
//在二叉排序树中查找值为key的结点（递归实现）
BSTNode *BST_search(BSTree T, int key)
{
    if (T == NULL)
        return NULL;
    if (T->key == key)
        return T;
    else
    {
        if (key < T->key)
            return BST_search(T->lchild, key);
        if (key > T->key)
            return BST_search(T->rchild, key);
    }
}
//二叉排序树的插入
int BST_Insert(BSTree &T, int k)
{
    if (T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1; //返回1，插入成功
    }
    else if (k == T->key)
        return 0;
    else if (k < T->key)
        return BST_Insert(T->lchild, k);
    else if (k > T->key)
        return BST_Insert(T->rchild, k);
}
//二叉排序树的构造   按照str[]中的关键字序列建造二叉排序树
void Creat_BST(BSTree &T, int str[], int n)
{
    T == NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(T, str[i]);
        i++;
    }
}
//中序遍历
void InOrder(BSTree T)
{
    if (T != NULL)
    {
        if (T->lchild)
            InOrder(T->lchild);
        printf("%d->", T->key);
        if (T->rchild)
            InOrder(T->rchild);
    }
}
//删除节点T
void deleteNode(BSTree &p) //把p当作根节点了，用递归删除值为key的节点
{
    /*BSTree q,s;
	if(!p->lchild)	
	{	//如果左子树为空，则只需重接其右子树
		//这里包含了左右子树均为空的情况
		q = p;
		p = p->rchild ;
		free(q);
	}
	else if(!p->rchild)
	{	//如果右子树为空，则只需重接其左子树
		q = p;
		p = p->lchild;
		free(q);
	}
	else
	{	//如果左右子树都不为空，我们采取第一种方法来重接左右子树，
		//我们这里采取修改左子树的方法，也可以修改右子树，方法类似
		s = p->lchild;		//取待删节点的左节点
 
		//一直向右，最终s为待删节点的前驱节点
		//如果将各节点元素按从小到大顺序排列成一个序列，
		//则某节点的前驱节点即为序列中该节点的前面一个节点
		while(s->rchild)
			s = s->rchild;
		s->rchild = p->rchild;	//将p的右子树接为s的右子树
		q = p;
		p = p->lchild;		//将p的左子树直接接到其父节点的左子树上
		free(q);
	}*/
    BSTNode *q, r, s;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        free(p);
        p = NULL;
    }
    if (p->lchild == NULL && p->rchild != NULL)
    {
        BSTNode *q = p;
        p = p->rchild;
        free(q);
    }
    if (p->rchild == NULL && p->lchild != NULL)
    {
        BSTNode *q = p;
        p = p->lchild;
        free(q);
    }
    if (p->rchild != NULL && p->lchild != NULL)
    {
        BSTNode *r = p->rchild;
        BSTNode *s = p->lchild;
        while (s->rchild != NULL)
        {
            s = s->rchild;
        }
        s->rchild = r;
        BSTNode *q = p;
        p = p->lchild;
        free(q);
    }
}
/*
若T所指向的二叉排序树中查找到关键字为key的数据元素，
则删除该元素对应的节点，并返回true，否则返回false
如果要删除的恰好是根节点，则会改变根节点的值，因此要传入引用
*/
bool delete_BSTree(BSTree &T, int key)
{
    //不存在关键字为key的节点
    if (!T)
        return false;
    else
    {
        if (key == T->key) //查找到关键字为key的节点
        {
            deleteNode(T);
            return true;
        }
        else if (key < T->key) //继续查找左子树
            return delete_BSTree(T->lchild, key);
        else //继续查找右子树
            return delete_BSTree(T->rchild, key);
    }
}
int main()
{
    int str[] = {20, 14, 26, 7, 16, 17, 21, 30};
    int n = 8;
    int m = 17;
    BSTree T = NULL;
    Creat_BST(T, str, n);
    InOrder(T);
    printf("\n");
    //   BSTree p=BST_Search(T,16);
    delete_BSTree(T, 14);
    InOrder(T);
    printf("\n");
    BST_Insert(T, 60);
    InOrder(T);
    system("pause");
}
