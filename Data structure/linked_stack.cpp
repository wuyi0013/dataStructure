#include <stdio.h>//
#include <stdlib.h>
#define maxsize 10
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode, *LinkStack;
//链栈初始化
bool Init_linked_stack(LinkStack &s)
{
    s=NULL;
    return true;
}
//入栈
bool Push(LinkStack &s,int x)
{
    LinkNode *q;
    q=(LinkNode *)malloc(sizeof(LinkNode));
    q->next=s;
    q->data=x;
    s=q;
    return true;
}
//出栈
bool Pop(LinkStack &s,int &x)
{
    LinkNode *q=s;
    if(s==NULL)
        return false;
    x=s->data;
    s=s->next;
    free(q);
    return true;
}
//获取栈顶元素
int GetTop(LinkStack s)
{
    if(s!=NULL)
        return s->data;
}
//建立一个栈,输入9999终止
void BuildStack(LinkStack &s)
{   
    int x;
    printf("Build Stack\nPlease input your data:\n");
    scanf("%d",&x);
    while(x!=9999)
    {
        Push(s,x);
        scanf("%d",&x);
    }
}

//输出栈中全部元素
void PrintStack(LinkStack s)
{
    while(s->next!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("%d\n",s->data);
}
int main()
{
    LinkStack s;
    Init_linked_stack(s);
    BuildStack(s);
    PrintStack(s);
    Push(s,2);
    PrintStack(s);
    system("pause");
}

