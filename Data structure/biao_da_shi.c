#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000 + 10
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define OVERFLOW 0
#define ERROR 0

char str[N];
typedef int Status;
typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

unsigned char prior[7][7] = {
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', ' '},
    {'<', '<', '<', '<', '<', ' ', '>'},
    {'<', '<', '<', '<', '<', ' ', '='}};

char OPSET[7] = {'+', '-', '*', '/', '(', ')', '#'};

Status InitStack(SqStack *s) //��ʼ��ջ
{

    s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!s->base)
        exit(OVERFLOW);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack *s, SElemType c) //��ջ
{

    if ((s->top - s->base) >= s->stacksize)
    {

        s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!s->base)
            exit(OVERFLOW);
        s->stacksize += STACKINCREMENT;
    }
    *(s->top)++ = c;
    return OK;
}

Status GetTop(SqStack *s) //ȡջ��Ԫ��
{

    SElemType e;
    if (s->base == s->top)
        return ERROR;
    e = *(s->top - 1);
    return e;
}

Status In(char c, char str[]) //�ж��Ƿ�Ϊ�����
{

    int i = 0;
    while (c != str[i])
    {

        i++;
    }

    if (i < 7)
        return OK;
    return ERROR;
}

void Strcat(char *str1, char *str2) //�ַ������Ӻ��������ַ��� str2 ���ӵ� str1 ��
{

    int i = 0, j = 0;
    while (str1[i] != '\0')
    {

        i++;
    }

    while (str2[j] != '\0')
    {

        str1[i++] = str2[j++];
    }

    str1[i] = '\0';
}

Status Atoi(char *c) //���ַ���תΪ����
{

    int data = 0, d = 0;
    int i = 0;
    while (c[i] != '\0')
    {

        data = data * 10 + c[i] - '0';
        i++;
    }
    return data;
}

Status precede(int a, char b) //�ж����ȼ�����
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

Status Pop(SqStack *s) //�����ź���
{

    int e;
    if (s->base == s->top)
        return ERROR;
    e = *--(s->top);
    return e;
}

Status Opereta(int a, int b, int c) //���㺯��
{

    switch (b)
    {

    case '+':
        return a + c;
    case '-':
        return a - c;
    case '*':
        return a * c;
    case '/':
        return a / c;
    }

    return OK;
}

int EvaluateExpression(char *MyExpression) //�㷨 3.4
{                                          //�������ʽ��ֵ����������㷨��
    //�� OPTR �� OPND �ֱ�Ϊ�����ջ��������ջ 
    SqStack OPTR;//�����ջ���ַ�Ԫ�� 
    SqStack OPND;//������ջ��ʵ��Ԫ��

    char TempData[20];
    int data, a, b;
    char *c, Dr[2], e;
    int theta;

    InitStack(&OPTR);
    Push(&OPTR, '#');
    InitStack(&OPND);
    c = MyExpression;
    TempData[0] = '\0';
    while (*c != '#' || GetTop(&OPTR) != '#')
    {

        if (!In(*c, OPSET)) //������������ջ
        {

            Dr[0] = *c;
            Dr[1] = '\0';
            Strcat(TempData, Dr);
            c++;
            if (In(*c, OPSET)) //�������ʱ
            {

                data = Atoi(TempData);
                Push(&OPND, data);
                TempData[0] = '\0';
            }
        }

        else
        {

            switch (precede(GetTop(&OPTR), *c))
            {

            case '<':
                Push(&OPTR, *c);
                c++;
                break;
            case '=':
                Pop(&OPTR);

                c++;

                break;
            case '>':
                a = Pop(&OPND);
                b = Pop(&OPND);
                theta = Pop(&OPTR);
                Push(&OPND, Opereta(b, theta, a));
                break;
            }
        }
    }

    return GetTop(&OPND);
}

int main()
{
    while (scanf("%s", str) != EOF)
    {

        printf("%d\n", EvaluateExpression(str));
    }

    return 0;
}
