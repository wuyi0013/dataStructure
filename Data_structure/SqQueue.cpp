#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组,存储MaxSize-1个元素
	int front, rear;//队列头 队列尾
}SqQueue;
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
        return false;
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
    SqQueue Q;
	bool ret;//存储返回值
	ElemType element;//存储出队元素
	InitQueue(Q);//初始化循环队列
	ret = isEmpty(Q);
	if (ret)
	{
		printf("Queue is empty\n");
	}
	else {
		printf("Queue is not empty\n");
	}
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret = EnQueue(Q, 6);
	ret = EnQueue(Q, 7);
	if (ret)
	{
		printf("EnQueue successfully\n");
	}
	else {
		printf("EnQueue failed\n");
	}
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("DeQueue successfully, the element is %d\n", element);
	}
	else {
		printf("DeQueue failed\n");
	}
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("DeQueue successfully, the element is %d\n", element);
	}
	else {
		printf("DeQueue failed\n");
	}
    return 0;

}