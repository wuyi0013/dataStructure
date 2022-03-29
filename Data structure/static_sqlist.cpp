#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct
{
    int data[maxsize];
    int length;
} sqlist;
//初始化操作
void Initlist(sqlist &L)
{
    int i = 0;
    for (i = 0; i < maxsize; i++)
        L.data[i] = 0;
    L.length = 0;
}
//销毁操作
void destorylist(sqlist &L)
{
    L.length = 0;
}
//插入操作,在第i个位置插入指定元素e
bool ListInsert(sqlist &L, int i, int e)
{
    int j;
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= maxsize) //当前存储空间已满，不能插入
        return false;
    for (j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
//删除操作，删除第i个位置的元素并返回其值e
bool DeleteList(sqlist &L, int i, int &e)
{
    int j;
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (j = i - 1; j < L.length - 1; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}
//按值查找，找到元素e所在位置并返回其位序
int LocateElem(sqlist L, int e)
{
    int i = 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
//按位查找
int GetElem(sqlist L, int i)
{
    return L.data[i - 1];
}
//求表长
int Length(sqlist L)
{
    return L.length;
}
//输出表
void PrintList(sqlist L)
{
    for (int i = 0; i < L.length; i++)
        printf("L.data[%d]=%d\n", i, L.data[i]);
}
//判断是否是空表
bool EmptyList(sqlist L)
{
    if (L.length == 0)
        return false;
    else
        return true;
}
//将第i个元素的值修改为e
bool ChangeElem(sqlist &L, int i, int e)
{
    if (i < 1 || i > L.length)
        return false;
    L.data[i - 1] = e;
    return true;
}
//将顺序表的元素逆置
sqlist reverse_list(sqlist &L)
{
    int a[maxsize] = {0};
    for (int i = 0; i < L.length; i++)
    {
        a[i] = L.data[i];
    }
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = a[L.length - 1 - i];
    }
    return L;
}
//在顺序表插入一个数仍保持原来的顺序
sqlist Insert(sqlist &L,int k)
{
    int j=0;
    while(k>L.data[j]&&j<L.length)
    {
        j=j+1;
    }
    for(int i=L.length;i>j;i--)
    {
        L.data[i]=L.data[i-1];
    }
    L.data[j]=k;
    L.length++;
    return L;
}
//两个（有序或无序）顺序表的合并
sqlist combine_sqlist(sqlist L,sqlist P,sqlist &Q)
{
    int a[P.length+L.length]={0};
    Q.length=L.length+P.length;
    int j=0;
    int temp;
    for(int i=0;i<L.length;i++)
    {
        a[i]=L.data[i];
    }
    for(int i=L.length;i<L.length+P.length;i++)
    {
        a[i]=P.data[j];
        j++;
    }
    for(int i=1;i<L.length+P.length;i++)
    {
        for(j=0;j<L.length+P.length-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<L.length+P.length;i++)
    {
        Q.data[i]=a[i];
    }
    return Q;
}
/*int main()
{
    sqlist L;
    Initlist(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    L.length = 5;
    printf("%d\n", LocateElem(L, 2));
    ChangeElem(L,2,5);
    PrintList(L);
    destorylist(L);
    PrintList(L);  
    system("pause");
    return 0;
}*/
//在顺序表插入一个数仍保持原来的顺序
/*int main()
{
    sqlist L;
    int j=0;
    int k,i;
    Initlist(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 4;
    L.data[3] = 5;
    L.data[4] = 6;
    L.length = 5;
    printf("Input the num that u want to insert:\n");
    scanf("%d",&k);
    while(k>L.data[j]&&j<L.length)
    {
        j=j+1;
    }
    printf("%d\n",j);
    for(i=L.length;i>j;i--)
    {
        L.data[i]=L.data[i-1];
    }
    L.data[j]=k;
    L.length++;
    PrintList(L);
    system("pause");
    return 0;
}*/
//逆序输出
/*int main()
{
    sqlist L;
    int a[maxsize]={0};
    Initlist(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 4;
    L.data[3] = 5;
    L.data[4] = 6;
    L.length = 5;
    for(int i=0;i<L.length;i++)
    {
        a[i]=L.data[i];
    }
    for(int i=0;i<L.length;i++)
    {
        L.data[i]=a[L.length-1-i];
    }
    PrintList(L);
    system("pause");
    return 0;
}*/
int main()
{
    sqlist L,P,Q;
    int k;
    Initlist(L);
    Initlist(P);
    Initlist(Q);
    L.data[0] = 3;
    L.data[1] = 9;
    L.data[2] = 2;
    L.data[3] = 5;
    L.data[4] = 6;
    L.length = 5;
    P.data[0] = 7;
    P.data[1] = 8;
    P.data[2] = 9;
    P.data[3] = 60;
    P.length = 4;
    combine_sqlist(L,P,Q);
    PrintList(Q);
    system("pause");
    return 0;
}
