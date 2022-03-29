#include<stdio.h>
int digui(int i){
    if(i==0){
        return 0;
    }else if(i==1)
    {
        return 1;
    }else if(i==2)
    {
        return 2;
    }else if(i>2)
    {
        return digui(i-1)+digui(i-2);
    }
    
}
int main() {
    int i;
    scanf("%d",&i);
    printf("%d",digui(i));
	return 0;
}