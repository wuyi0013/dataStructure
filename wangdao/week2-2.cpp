#include<stdlib.h>
#include<stdio.h>


int main() {

	int i;
    char j;
    float k;
    float m;
	
    scanf("%d %c%f",&i,&j,&k);
    m=i+j+k;
    printf("%d %c %f\n",i,j,k);
    printf("%.2f",m);
	system("pause");

	return 0;
}