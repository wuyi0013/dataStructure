#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct
{
    int data[maxsize];
    int length;
}Sqlist;

void Initlist(Sqlist *L)
{
    int i;
    for(i=0;i<10;i++)
    {
        L->data[i]=0;
    }
    L->length=0;
}
int main()
{
    Sqlist *L;
    int i=0;
    Initlist(L);
    for(i=0;i<10;i++)
    {
        printf("%d ",L->data[i]);
    }
    system("pause");
    return 0;
}
