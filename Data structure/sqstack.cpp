#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct
{
    int data[maxsize];//静态数组存放栈中元素
    int top;//栈顶指针
}sqstack;
//初始化栈
void InitStack(sqstack &s)
{
    s.top=-1;
}
//判断栈空
bool StackEmpty(sqstack s)
{
    if(s.top==-1)
        return true;
    else
        return false;  
}
//新元素入栈
bool Push(sqstack &s,int x)
{
    if(s.top==maxsize-1)
        return false;
    s.data[++s.top]=x;
    return true;
}
//出栈操作
bool Pop(sqstack &s,int &x)
{
    if(s.top==-1)
        return false;
    x=s.data[s.top--];
    return true;
}
//输出栈中元素
void PrintStack(sqstack s)
{
    for(int i=0;i<=s.top;i++)
    {
        printf("s.data[i]=%d\n",s.data[i]);
    }
}
int main()
{
    int x;
    sqstack s;
    InitStack(s);
    if(StackEmpty(s))
        printf("kong\n");
    Push(s,3);
    Push(s,4);
    Push(s,5);
    Push(s,6);
    PrintStack(s);
    Pop(s,x);
    PrintStack(s);
    if(StackEmpty(s))
        printf("kong\n");
    system("pause");

}

