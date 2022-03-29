#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//整型指针
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len;//实际申请11个元素的空间
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	for(int i=0;i<ST.TableLen;i++)
    {
        scanf("%d",&ST.elem[i]);
    }
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
void InsertSort(ElemType A[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        if(A[i-1]>A[i])
        {
            k=A[i];
            for(j=i-1;A[j]>A[0]&&j>=0;--j)
            {
                A[j+1]=A[j];
            }
            A[j+1]=k;
        }
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
int main()
{
	SSTable ST;
	ST_Init(ST,10);//实际申请了11个元素空间
    BubbleSort(ST.elem,10);
    ST_print(ST);
    QuickSort(ST.elem,0,9);
    ST_print(ST);
	InsertSort(ST.elem,10);
	ST_print(ST);
	return 0;
}