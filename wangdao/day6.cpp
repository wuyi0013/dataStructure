#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50
typedef int ElemType;
typedef struct SqStack{
    ElemType data[Maxsize];
    int top;
}SqStack;
#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组,存储MaxSize-1个元素
	int front, rear;//队列头 队列尾
}SqQueue;
//初始化栈
void InitStack(SqStack &S)
{
    S.top=-1;
}
//栈是否为空
bool StackEmpty(SqStack S)
{
    if(S.top==-1)
    {
        return true;
    }
    return false;
}
//元素入栈
bool Push(SqStack& S, ElemType x)
{
    if(S.top==Maxsize)
        return false;
    S.data[++S.top]=x;
    return true;
}
//获取栈顶元素
bool GetTop(SqStack S, ElemType &x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top];
    return true;
}
//元素出栈
bool Pop(SqStack& S, ElemType& x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top--];
    return true;
}

void InitQueue(SqQueue& Q)
{
    Q.front=Q.rear=0;
}
bool isEmpty(SqQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    return false;
}
bool EnQueue(SqQueue& Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front)
    {
        printf("false");
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
int main()
{
    SqStack S;
	bool flag;
	ElemType m;//存储拿出来的栈顶元素的
	InitStack(S);//初始化
    for(int i=1;i<=3;i++)
    {
        scanf("%d",&m);
        Push(S,m);
    }
	for(int i=1;i<=3;i++)
    {
        Pop(S,m);
        printf("%2d",m);
    }
    printf("\n");
    SqQueue Q;
    InitQueue(Q);
    for(int i=1;i<=MaxSize;i++)
    {
        scanf("%d",&m);
        EnQueue(Q,m);
    }
    printf("\n");
    for(int i=1;i<=MaxSize-1;i++)
    {
        DeQueue(Q,m);
        printf("%2d",m);
    }
	return 0;
}