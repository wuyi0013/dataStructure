#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//存储元素的起始地址
	int TableLen;//元素个数
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;
	}
}
void ST_print(SSTable ST)
{
	for(int i=0;i<ST.TableLen;i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
void BubbleSort(ElemType A[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        bool flag=true;;
        for(int j=n-1;j>i;j--)
        {
            if(A[j-1]>A[j])
            {
                temp=A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
                flag=false;
            }
        }
        if(flag==true)
            break;
    }
}
void SelectSort(ElemType A[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
				min=j;
		}
		if(min!=i)
		{
			int temp=A[min];
			A[min]=A[i];
			A[i]=temp;
		}
	}
}
int main()
{
	SSTable ST;
	ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
	ST_Init(ST,10);//初始化
	//memcpy(ST.elem,A,sizeof(A));
	ST_print(ST);
	//BubbleSort(ST.elem,10);
	SelectSort(ST.elem,10);
    ST_print(ST);
	system("pause");
}