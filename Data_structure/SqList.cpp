#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef int Elemtype;

typedef struct{
    Elemtype data[MaxSize];
    int len;
}Sqlist;
//在第i个位置插入元素j
bool SqlistInsert(Sqlist &L,int i,Elemtype j)
{
    if(i<1||i>L.len+1)
        return false;
    if(L.len>=MaxSize)
        return false;
    for(int k=L.len;k>=i;k--)
    {
        L.data[k]=L.data[k-1];
    }
    L.data[i-1]=j;
    L.len++;
    return true;
}
//删除第i个元素
bool SqlistDelete(Sqlist &L,int i)
{
    if(i<1||i>L.len)
        return false;
    for(int j=i;j<L.len;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.len--;
    return true;
}
//打印
void PrintList(Sqlist L)
{
    for(int i=0;i<L.len;i++)
    {
        printf("%3d",L.data[i]);
    }
    printf("\n");
}
//查找成功，返回位置，位置从1开始，查找失败，返回0
int LocateElem(Sqlist L,Elemtype i)
{
    int j=0;
    for(;j<L.len;j++)
    {
        if(L.data[j]==i)
            return j+1;
    }
    return 0;
}
int main(){
    Sqlist L;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.len=3;
    int i;
    scanf("%d",&i);
    int k;
    scanf("%d",&k);
    bool ret=SqlistInsert(L,2,i);
    if(ret)
        PrintList(L);  
    ret=SqlistDelete(L,k);
    if(ret)
    {
        PrintList(L);
    }else
    {
        printf("false");
    }
    return 0;
}