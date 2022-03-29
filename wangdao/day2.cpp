#include<stdio.h>
#include<stdlib.h>
void f(char* &p){
    p=(char*)malloc(100);
    fgets(p,100,stdin);
}
int main(){
    char* p;
    f(p);
    puts(p);
    return 0;
}