#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
typedef struct
{
    char data[maxsize]; //静态数组存放栈中元素
    int top;            //栈顶指针
} sqstack;
//初始化栈
void InitStack(sqstack &s)
{
    s.top = -1;
}
//判断栈空
bool StackEmpty(sqstack s)
{
    if (s.top == -1)
        return true;
    else
        return false;
} //新元素入栈
bool Push(sqstack &s, char x)
{
    if (s.top == maxsize - 1)
        return false;
    s.data[++s.top] = x;
    return true;
}
//出栈操作
bool Pop(sqstack &s, char &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top--];
    return true;
}
//判断字符串括号是否匹配
bool bracketCheck(char str[], int length)
{
    sqstack s;
    char topelem;
    InitStack(s);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(s, str[i]);
        else
        {
            if (StackEmpty(s))//第二处逻辑错误，必须下一个是右括号，栈空，才能确定右括号单身，返回false
                return false;
            Pop(s, topelem);//第三处逻辑错误，括号已经被pop了，后面肯定false
            if (str[i] == ')' && topelem != '(')
                return false;
            if (str[i] == ']' && topelem != '[')
                return false;
            if (str[i] == '}' && topelem != '{')
                return false;
        }
    }
    return StackEmpty(s);
}
/*int main()
{
    char str[100];
    int length=0;
    printf("Input your words:\n");
    for(int i=0;i<100;i++)
    {
        str[i]=getchar();
        length++;
        if(str[i]=='@')
            {
                length--;//第一处逻辑错误（只能括号比较）
                break;
            }
    }
    if(bracketCheck(str,length))
        printf("Match");
    else
        printf("Don't match");
    system("pause");
    return 0;
}
*/
int main()
{
    char str[7]="{[()]}";
    int length=6;
    if(bracketCheck(str,length))
        printf("Match");
    else
        printf("Don't match");
    system("pause");
    return 0;
}
