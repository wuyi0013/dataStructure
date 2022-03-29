#include<stdlib.h>
#include<stdio.h>


int main() {

	int i;
    char j;
    float k;
	
    scanf("%d %c%f",&i,&j,&k);
    printf("%d %c %f\n",i,j,k);
    printf("%.2f",i+j+k);
	system("pause");

	return 0;
}