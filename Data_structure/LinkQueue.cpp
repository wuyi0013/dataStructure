#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;//链表头 链表尾
}LinkQueue;//先进先出
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    Q.rear->next=NULL;
}
bool IsEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    return false;
}
//入队，尾部插入法
void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=Q.rear->next;
    Q.rear->next=s;
    Q.rear=s;
}
//出队  头部删除法
bool DeQueue(LinkQueue &Q,ElemType &x)
{
    if(IsEmpty(Q))
        return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.front=Q.rear;
    free(p);
    return true;
}
int main()
{
	LinkQueue Q;
	bool ret;
	ElemType element;//存储出队元素
	InitQueue(Q);
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6);
	EnQueue(Q,7);
	ret=DeQueue(Q,element);
	if(ret)
	{
		printf("DeQueue successfully, the element is %d\n",element);
	}else{
		printf("DeQueue failed\n");
	}
	//system("pause");
}