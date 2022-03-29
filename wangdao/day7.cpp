#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
typedef struct BiNode{
    BiElemType data;
    struct BiNode* lchild;
    struct BiNode* rchild;
}BiNode,*BiTree;
typedef struct tag{
    BiTree p;
    struct tag* pnext;
}tag_t,*ptag_t;
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
int main()
{
    BiTree tree=NULL;
    BiTree pnew;
    BiElemType c;
    ptag_t phead=NULL;
    ptag_t ptail=NULL;
    ptag_t listpnew=NULL;
    ptag_t pcur=NULL;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')
        {
            break;
        }
        pnew=(BiTree)calloc(1,sizeof(BiNode));
        pnew->data=c;
        listpnew=(ptag_t)calloc(1,sizeof(tag_t));
        listpnew->p=pnew;
        if(tree==NULL)
        {
            tree=pnew;
            phead=listpnew;
            ptail=listpnew;
            pcur=listpnew;
        }else{
            ptail->pnext=listpnew;
            ptail=ptail->pnext;
            if(pcur->p->lchild==NULL)
            {
                pcur->p->lchild=pnew;
            }else if(pcur->p->rchild==NULL)
            {
                pcur->p->rchild=pnew;
                pcur=pcur->pnext;
            }
        }
        
    }
    printf("--------preOrder----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
	preOrder(tree);
	printf("\n--------inOrder------------\n");//先打印左孩子，打印父亲，打印右孩子
	inOrder(tree);
	printf("\n--------postOrder------------\n");//先打印左孩子，打印右孩子，最后打印父亲
	postOrder(tree);
	printf("\n--------InOrder2------\n");//重要性低
	//InOrder2(tree); 
	printf("\n--------levelTraversal-----------\n");
	//LevelOrder(tree);
	printf("\n");
    return 0;
}