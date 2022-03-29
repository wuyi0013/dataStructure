#include <stdio.h>
#include <stdlib.h>
#define initsize 10
typedef struct
{
    int *data;
    int maxsize;
    int length;
} seqlist;
//初始化操作
void Initseqlist(seqlist &L)
{
    L.data = (int *)malloc(initsize * sizeof(int));
    L.length = 0;
    L.maxsize = initsize;
}
//销毁操作
void Destoryseqlist(seqlist &L)
{
    free(L.data);
    L.length = 0;
}
//插入操作，在表的第i个位置插入元素e
bool SeqlistInsert(seqlist &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= L.maxsize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}
//删除操作，删除表的第i个元素并将其值返回
bool SeqlistDelete(seqlist &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}
//将表的最大容量增加len
void IncreaseSeqlist(seqlist &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.maxsize + len) * sizeof(int));
    for (int j = 0; j < L.length; j++)
        L.data[j] = p[j];
    L.maxsize = L.maxsize + len;
    free(p);
}
//按位查找
int GetElem(seqlist L, int i)
{
    return L.data[i - 1];
}
//按值查找
int LocateElem(seqlist L, int e)
{
    for (int j = 0; j < L.length; j++)
    {
        if (L.data[j] == e)
            return j + 1;
    }
    return 0;
}
//求表长
int Length(seqlist L)
{
    return L.length;
}
//输出表
void PrintList(seqlist L)
{
    for (int i = 0; i < L.length; i++)
        printf("L.data[%d]=%d\n", i, L.data[i]);
}
//判断是否是空表
bool EmptyList(seqlist L)
{
    if (L.length == 0)
        return false;
    else
        return true;
}
//将第i个元素的值修改为e
bool ChangeElem(seqlist &L, int i, int e)
{
    if (i < 1 || i > L.length)
        return false;
    L.data[i - 1] = e;
    return true;
}

int main()
{
    seqlist L;
    Initseqlist(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    L.length = 5;
    printf("%d\n", LocateElem(L, 2));
    ChangeElem(L, 2, 5);
    PrintList(L);
    Destoryseqlist(L);
    PrintList(L);
    system("pause");
    return 0;
}
