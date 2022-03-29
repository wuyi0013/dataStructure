#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct SqStack{
    ElemType data[MaxSize];
    int top;
}SqStack;
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
    if(S.top==MaxSize)
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
int main()
{
    SqStack S;
	bool flag;
	ElemType m;//存储拿出来的栈顶元素的
	InitStack(S);//初始化
	flag = StackEmpty(S);
	if (flag)
	{
		printf("Stack is empty\n");
	}
	Push(S, 3);//入栈元素3
	Push(S, 4);//入栈元素4
	Push(S, 5);
	flag = GetTop(S, m);//获取栈顶元素,但是S.top值不变
	if (flag)
	{
		printf("The top element of the stack is %d\n", m);
	}
	flag = Pop(S, m);//弹出栈顶元素
	if (flag)
	{
		printf("The popped element is %d\n", m);
	}
	return 0;
}