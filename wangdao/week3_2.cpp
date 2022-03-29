#include<stdio.h>
int main(){
    int a[100];
    int b;
    int sum=0;
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<b;i++)
    {
        if(a[i]==2)
            sum++;
    }
    printf("%d",sum);
}