#define maxsize 10
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int data[maxsize];
	int length;
}Sqlist;
void InitList(Sqlist &L)
{
	for(int i=0;i<maxsize;i++)
		L.data[i]=0;
	L.length=0;
}
void ListInsert(Sqlist &L,int i,int e)
{
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
}
main(void) 
{
	int i,j;
	Sqlist L;
	InitList(L);
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=3;
	L.data[3]=4;
	L.data[4]=5;
	L.length=5;
	printf("This is the initial data");
	for(i=0;i<maxsize;i++)
		printf("%d  ",L.data[i]);
	printf("\nInput the position and num that you want");
	scanf("%d%d",&i,&j);
	ListInsert(L,i,j);
	for(i=0;i<maxsize;i++)
		printf("%d ",L.data[i]);
}