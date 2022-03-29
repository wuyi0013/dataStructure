#include <stdio.h>
#include <stdlib.h>
#define Initsize 100
#define Increament 10
typedef struct
{
    int *base; //动态顺序栈
    int *top;
    int stacksize;
} sqstack;
typedef struct
{
    char *base; //动态顺序栈
    char *top;
    char stacksize;
} Sqstack;
char prior[7][7] = {
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', ' '},
    {'<', '<', '<', '<', '<', ' ', '>'},
    {'<', '<', '<', '<', '<', ' ', '='}};

char OPSET[7] = {'+', '-', '*', '/', '(', ')', '#'};
//初始化栈
bool InitStack(sqstack &s)
{
    s.base = (int *)malloc(sizeof(int) * Initsize);
    if (!s.base)
        return false;
    s.top = s.base;
    s.stacksize = Initsize;
    return true;
}
//判断栈空
bool StackEmpty(sqstack s)
{
    if (s.top == s.base)
        return true;
    else
        return false;
}
//新元素入栈
bool Push(sqstack &s, int x)
{
    if (s.top - s.base >= s.stacksize) //理解为动态数组，指针类型的运算都转化成类似数组那种了
    {
        s.base = (int *)realloc(s.base, (s.stacksize + Increament) * sizeof(int));
        if (!s.base)
            return false;
        s.top = s.base + s.stacksize;
        s.stacksize += Increament;
    }
    *s.top++ = x;
    return true;
}
//出栈操作
bool Pop(sqstack &s, int &x)
{
    if (s.top == s.base)
        return false;
    x = *--s.top;
    return true;
}
//输出栈中元素
void PrintStack(sqstack s)
{
    int x = s.top - s.base;
    for (int i = 0; i < x; i++)
    {
        printf("%d", *s.base++);
    }
}
//判断进栈的是不是运算符
bool In(char c, char str[])
{
    int i = 0;
    while (c != str[i])
        i++;
    if (i < 7)
        return true;
    else
        return false;
}
//获取栈顶元素
int GetTop(sqstack s)
{
    int *e;
    if (s.base == s.top)
        return -1;
    e = s.top - 1;
    return *e;
}
bool InitStack(Sqstack &s)
{
    s.base = (char *)malloc(sizeof(char) * Initsize);
    if (!s.base)
        return false;
    s.top = s.base;
    s.stacksize = Initsize;
    return true;
}
//判断栈空
bool StackEmpty(Sqstack s)
{
    if (s.top == s.base)
        return true;
    else
        return false;
}
//新元素入栈
bool Push(Sqstack &s, char x)
{
    if (s.top - s.base >= s.stacksize) //理解为动态数组，指针类型的运算都转化成类似数组那种了
    {
        s.base = (char *)realloc(s.base, (s.stacksize + Increament) * sizeof(char));
        if (!s.base)
            return false;
        s.top = s.base + s.stacksize;
        s.stacksize += Increament;
    }
    *s.top++ = x;
    return true;
}
//出栈操作
char pop(Sqstack &s)
{
    if (s.top == s.base)
        return false;

    return *--s.top;
}
//输出栈中元素
void PrintStack(Sqstack s)
{
    int x = s.top - s.base;
    for (int i = 0; i < x; i++)
    {
        printf("%d", *s.base++);
    }
}

//获取栈顶元素
char GetTop(Sqstack s)
{
    char *e;
    if (s.base == s.top)
        return -1;
    e = s.top - 1;
    return *e;
}
char precede(char a, char b) //判断优先级函数
{

    int i = 0, j = 0;
    while (OPSET[i] != a)
    {

        i++;
    }

    while (OPSET[j] != b)
    {

        j++;
    }

    return prior[i][j];
}
int Operate(int a, char c, int b)
{
    switch (c)
    {

    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}
int EvaluateExpression()
{
    char c;
    char x;
    char theta;
    int a, b, d;
    Sqstack OPTR;
    Push(OPTR, '#');
    sqstack OPND;
    c = getchar();
    while (c != '#' || GetTop(OPTR) != '#')
    {
        if (!In(c, OPSET)) //不是运算符进栈
        {
            c = c - 48;
            Push(OPND, c);
            c = getchar();
        }
        else
        {
            switch (precede(GetTop(OPTR), c))
            {
            case '<': //栈顶元素优先权低
                Push(OPTR, c);
                c = getchar();
                break;
            case '=': //脱括号并接受下一个字符
                x = pop(OPTR);
                c = getchar();
                break;
            case '>': //退栈并将运算结果入栈
                theta = pop(OPTR);
                Pop(OPND, a);
                Pop(OPND, b);
                Push(OPND, Operate(a, theta, b));
                c=getchar();
                break;
            }
        }
    }
    return GetTop(OPND);
}
int main()
{
    int y;
    printf("Please input your evaluate expressions:\n");
    y = EvaluateExpression();
    printf("%d\n", y);
}
