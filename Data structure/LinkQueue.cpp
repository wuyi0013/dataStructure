#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;  
}LinkNode;
typedef struct
{
    LinkNode *rear,*front;
}LinkQueue;
//初始化队列(带头节点)
void InitQueue(LinkQueue &q)
{
    q.front=q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    q.front->next=NULL;//初始时rear和front都指向头节点
}
//初始化队列(不带头结点)
void initQueue(LinkQueue &q)
{
    q.rear=q.front=NULL;
}
//判断队列是否为空
bool EmptyQueue(LinkQueue q)
{
    if(q.front==q.rear)
        return true;
    else
        return false;    
}
//入队(带头节点)
bool EnQueue(LinkQueue &q,int x)
{
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    q.rear->next=s;
    q.rear=s;
    return true;
}
//入队(不带头结点)
bool enQueue(LinkQueue &q,int x)
{
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    if(q.front==NULL)
    {
        q.front=q.rear=s;
    }
    else
    {
        q.rear->next=s;
        q.rear=s;
    }
    return true;
}
//出队(带头节点)
bool DeQueue(LinkQueue &q,int &x)
{
    if(q.front==q.rear)
    return false;
    LinkNode *s=q.front->next;
    x=s->data;
    q.front->next=s->next;
    if(q.rear==s)
        q.rear=q.front;
    free(s);
    return true;    
}
//出队(不带头结点)
bool deQueue(LinkQueue &q,int &x)
{
    if(q.front=NULL)
        return false;
    LinkNode *s=q.front;
    x=s->data;
    q.front=s->next;
    if(q.rear==s)
        q.front=q.rear=NULL;
    free(s);
    return true;
}
//销毁(带头节点)
void DestoryQueue(LinkQueue &q)
{
    LinkNode *s,*p;
    s=q.front->next;
    while(s!=q.rear)
    {   
        p=s;
        s=s->next;
        free(p);
    }
    free(s);
    q.rear=q.front;
}

//输出队列(带头节点)
bool PrintQueue(LinkQueue q)
{
    if(q.front==q.rear)
        return false;
    LinkNode *s=q.front->next;
    while(s!=q.rear)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("%d\n",s->data);
    return true;
}
//建立一个链队列，输入9999时终止
void BuildQueue(LinkQueue &q)
{
    int x;
    printf("Build Queue\nPlease input your data:\n");
    scanf("%d",&x);
    while(x!=9999)
    {
        EnQueue(q,x);
        scanf("%d",&x);
    }
}
int main()
{
    int x;
    LinkQueue q;
    InitQueue(q);
    BuildQueue(q);
    PrintQueue(q);
    DeQueue(q,x);
    printf("%d\n",x);
    PrintQueue(q);
    EnQueue(q,3);
    PrintQueue(q);
    DestoryQueue(q);
    PrintQueue(q);
    system("pause");
}









