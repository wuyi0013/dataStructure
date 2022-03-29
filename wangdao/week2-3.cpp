#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
int main() {
	int i;
    int temp1,temp2=0;
    scanf("%d",&i);
    temp1=i;
    while(i)
    {
        temp2*=10;
        temp2+=i%10;
        i/=10;
    }
    if(temp1==temp2)
        printf("yes");
    else
        printf("no");

	return 0;
}