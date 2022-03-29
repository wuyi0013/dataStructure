#include<iostream>
using namespace std;

int main() {
/*
    float a=1111111;
	cout << a << endl;

	system("pause");

	return 0;
*/
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