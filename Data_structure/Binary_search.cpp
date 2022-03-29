#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//整型指针
	int TableLen;//存储动态数组里边元素的个数
}SSTable;
void ST_Init(SSTable &ST,int len)
{
    ST.TableLen=len+1;//多申请了一个位置,为了存哨兵
    ST.elem=(ElemType*)malloc(ST.TableLen*sizeof(ElemType));
    srand(time(NULL));
    for(int i=0;i<ST.TableLen;i++)
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
int Search_Seq(SSTable ST,ElemType key)
{
    ST.elem[0]=key;
    int i=ST.TableLen-1;
    for(;ST.elem[i]!=key;)
    {
        i--;
    }
    return i;
}
int Binary_Search(SSTable L,ElemType key)
{
    int low=0;
    int high=L.TableLen-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(L.elem[mid]==key)
        {
            return mid;
        }else if(L.elem[mid]<key)
        {
            low=mid+1;
        }else{
            high=mid-1;
        }
        
        
    }
    return -1;
}
int compare(const void *left,const void *right)//left，right是任意两个元素的地址值
{
	return *(ElemType*)left-*(ElemType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//从大到小
}
//顺序查找 与  折半查找
int main()
{
	SSTable ST;
	ElemType key;
	int pos;//存储查询元素的位置
	ST_Init(ST,10);
	ST_print(ST);
	printf("Please input the key that u search:\n");
	scanf("%d",&key);
	pos=Search_Seq(ST,key);
	if(pos)
	{
		printf("Successfully find,the pos is %d\n",pos);
	}else{
		printf("Search failed\n");
	}
	qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//qsort实现的是快排
	ST_print(ST);
	printf("Binary search,Please input the key that u search:\n");
	scanf("%d",&key);
	//有序数组
	pos=Binary_Search(ST,key);//二分查找，也叫折半查找
	if(pos!=-1)
	{
		printf("Successfully find,the pos is %d\n",pos);
	}else{
		printf("Search failed\n");
	}
	system("pause");
}
