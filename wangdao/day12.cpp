#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)//申请空间，并进行随机数生成
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	for(i=1;i<ST.TableLen;i++)
	{
		scanf("%d",&ST.elem[i]);
	}
}
void ST_print(SSTable ST)
{
	for(int i=1;i<ST.TableLen;i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
void swap(ElemType &a,ElemType &b)
{
	ElemType tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void SelectSort(ElemType A[],int n)
{
	int i,j,min;//min记录最小的元素的下标
	for(i=1;i<n;i++)//最多可以为8
	{
		min=i;
		for(j=i+1;j<=n;j++)//j最多可以为9
		{
			if(A[j]<A[min])
				min=j;
		}
		if(min!=i)
		{
			swap(A[i],A[min]);
		}
	}
}
//调整某个父亲节点
void AdjustDown(ElemType A[],int k,int len)
{
	int i;
	A[0]=A[k];
	for(i=2*k;i<=len;i*=2)
	{
		if(i<len&&A[i]<A[i+1])//左子节点与右子节点比较大小
			i++;
		if(A[0]>=A[i])
			break;
		else{
			A[k]=A[i];
			k=i;
		}
	}
	A[k]=A[0];
}
//用数组去表示树   层次建树
void BuildMaxHeap(ElemType A[],int len)
{
	for(int i=len/2;i>0;i--)
	{
		AdjustDown(A,i,len);
	}
}
void HeapSort(ElemType A[],int len)
{
	int i;
	BuildMaxHeap(A,len);//建立大顶堆
	for(i=len;i>1;i--)
	{
		swap(A[i],A[1]);
		AdjustDown(A,1,i-1);
	}
}
//《王道C督学营》课程
//选择排序与堆排序
int main()
{
	SSTable ST;
	ST_Init(ST,11);//初始化
	SelectSort(ST.elem,10);
    ST_print(ST);
	HeapSort(ST.elem,10);//零号元素不参与排序
	ST_print(ST);
	return 0;
}