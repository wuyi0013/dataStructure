#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef int Elemtype;

typedef struct{
    Elemtype data[MaxSize];
    int len;
}Sqlist;
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
void PrintList(Sqlist L)
{
    for(int i=0;i<L.len;i++)
    {
        printf("%3d",L.data[i]);
    }
    printf("\n");
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