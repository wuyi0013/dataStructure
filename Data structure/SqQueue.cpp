#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct
{
    int data[maxsize];
    int front,rear;//队头指针和队尾指针
}SqQueue;
//初始化顺序栈
void InitQueue(SqQueue &q)
{
    q.rear=q.front=0;
}
//判断队列是否为空
bool QueueEmpty(SqQueue q)
{
    if(q.rear=q.front)
        return true;
    else 
        return false;
}
//入队
bool EnQueue(SqQueue &q,int x)
{
    if((q.rear+1)%maxsize==q.front)
        return false;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%maxsize;
    return true;
}
//出队
bool DeQueue(SqQueue &q,int &x)
{
    if(q.rear==q.front)
        return false;
    x=q.data[q.front];
    q.front=(q.front+1)%maxsize;
    return true;
}
//队列元素的个数
int ElementQuality(SqQueue q)
{
    return (q.rear+maxsize-q.front)%maxsize;
}