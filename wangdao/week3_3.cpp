#include<stdio.h>
#include <string.h>
int main()
{
    char a[100];
    char b[100]={'\0'};
    gets(a);
    int i=0;
    while(a[i]!=0)
    {
        i++;
    }
    for(int j=0;j<i;j++)
    {
        b[j]=a[i-j-1];
    }
    //puts(a);
    //puts(b);
    int ret=strcmp(a,b);
    if(ret>0)
    {
        printf("%d",1);
    }else if(ret==0)
    {
        printf("%d",0);
    }else if(ret<0)
    {
        printf("%d",-1);
    }
    return 0;
}