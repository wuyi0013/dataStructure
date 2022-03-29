#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000 + 10
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define OVERFLOW 0
#define ERROR 0
typedef char Status;
typedef char SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;
Status InitStack(SqStack &s) //初始化栈
{

    s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s.base)
        exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &s, SElemType c) //入栈
{

    if ((s.top - s.top) >= s.stacksize)
    {

        s.base = (SElemType *)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!s.base)
            exit(OVERFLOW);
        s.stacksize += STACKINCREMENT;
    }
    *s.top++ = c;
    return OK;
}

Status GetTop(SqStack &s) //取栈顶元素
{

    SElemType e;
    if (s.base == s.top)
        return ERROR;
    e = *(s.top - 1);
    return e;
}
Status Pop(SqStack &s, SElemType &x)
{
    if (s.top == s.base)
        return ERROR;
    x = *--s.top;
    return OK;
}
int main()
{
    char c;
    SqStack s;
    InitStack(s);
    int i=0;
    char a[20];
    char b[20];
    printf("Please Input your words\n");
    gets(a);
    while(a[i]!='0')
    {
        Push(s,a[i]);
        i++;
    }
    i=0;
    while(!(s.top==s.base))
    {
        Pop(s,c);
        b[i]=c;
    }
    if(strcmp(a,b)==0)
        printf("Dui chen");
    else
    	printf("BU dui chen");
    getchar();
    return 0;   
}