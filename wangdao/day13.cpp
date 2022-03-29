#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef int ElemType;
void Merge(ElemType A[],int low,int mid,int high)
{
    ElemType B[N];
    int i,j,k;
    for(int i=low;i<=high;i++)
    {
        B[i]=A[i];
    }    
    for(i=low,j=mid+1,k=low;i<=mid&&j<=high;k++)
    {
        if(B[i]<=B[j])
        {
            A[k]=B[i++];
        }else{
            A[k]=B[j++];
        }
    }
    while(i<=mid)
    {
        A[k++]=B[i++];
    }
    while(j<=high)
    {
        A[k++]=B[j++];
    }

}
void MergeSort(ElemType A[],int low,int high)//递归分割
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
void print(int* a)
{
    for(int i=0;i<N;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n");
}
int main()
{
	int A[10]={12,63,58,95,41,35,65,0,38,44};
    /*for(int i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
    }*/
	MergeSort(A,0,9);
	print(A);
    system("pause");
    return 0;
}
