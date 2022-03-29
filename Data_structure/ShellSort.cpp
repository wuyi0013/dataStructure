#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//整型指针
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len+1;//实际申请11个元素的空间
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;//随机了11个数，但是第一个元素是没有用到的
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
//希尔排序  
//多轮插入排序，考的概率很低，因为编写起来复杂，同时效率并不如快排，堆排
void ShellSort(ElemType A[],int n)
{
    int dk,i,j;
    for(dk=n/2;dk>=1;dk/=2)
    {
        for(i=1+dk;i<=n;i++)
        {
            if(A[i]<A[i-dk])
            {
                A[0]=A[i];
                for(j=i-dk;j>0&&A[j]>A[0];j=j-dk)
                    A[j+dk]=A[j];
                A[j+dk]=A[0];
            }
            
        }
    }
}
int main()
{
	SSTable ST;
	ST_Init(ST,10);//实际申请了11个元素空间
	ST_print(ST);
    ShellSort(ST.elem,10);
	ST_print(ST);
	system("pause");
}