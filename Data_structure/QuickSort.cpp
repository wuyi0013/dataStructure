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
int Partition(int* arr, int left, int right)
{
    int temp,i,k;
    for(i=left,k=left;i<right;i++)
    {
        if(arr[i]<arr[right])
        {
            temp=arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
            k++;
        }
    }
    temp=arr[k];
    arr[k]=arr[right];
    arr[right]=temp;
    return k;
}
void QuickSort(ElemType A[],int low,int high)
{
    if(low<high)
    {
        int pos=Partition(A,low,high);
        QuickSort(A,low,pos-1);
        QuickSort(A,pos+1,high);
    }
}
int main()
{
	SSTable ST;
	ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78};
	ST_Init(ST,10);//初始化
	memcpy(ST.elem,A,sizeof(A));
	ST_print(ST);
	QuickSort(ST.elem,0,9);
    ST_print(ST);
	system("pause");
}