#include <stdio.h>
#include <stdlib.h>
#define Initsize 100
#define Increament 10
typedef struct
{
    int *base;//动态顺序栈
    int *top;
    int stacksize;
}sqstack;
//初始化栈
bool InitStack(sqstack &s)
{
    s.base=(int *)malloc(sizeof(int)*Initsize);
    if(!s.base)
        return false;
    s.top=s.base;
    s.stacksize=Initsize;
    return true;
}
//判断栈空
bool StackEmpty(sqstack s)
{
    if(s.top==s.base)
        return true;
    else
        return false;  
}
//新元素入栈
bool Push(sqstack &s,int x)
{
    if(s.top-s.base>=s.stacksize)//理解为动态数组，指针类型的运算都转化成类似数组那种了
    {
        s.base=(int *)realloc(s.base,(s.stacksize+Increament)*sizeof(int));
        if(!s.base)
            return false;
        s.top=s.base+s.stacksize;
        s.stacksize+=Increament;
    }
    *s.top++=x;
    return true;
}
//出栈操作
bool Pop(sqstack &s,int &x)
{
    if(s.top==s.base)
        return false;
    x=*--s.top;
    return true;
}
//输出栈中元素
void PrintStack(sqstack s)
{
    int x=s.top-s.base;
    for(int i=x;i>0;i--)
    {
        printf("%d",*--s.top);      
    }
     printf("\n");
}
//进制转换
void conversion(sqstack &s,int x,int y)
{
    while(y)
    {
        Push(s,y%x);
        y=y/x;
    }
}
int main()
{
    printf("Please input the jin_zhi and num:\n");
    int x,y;
    sqstack s;
    scanf("%d%d",&x,&y);
    InitStack(s);
    conversion(s,x,y);
    PrintStack(s);
    system("pause");
    return 0;
}