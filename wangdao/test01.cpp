#include<stdio.h>
int main () {
         int arr[5]={1,2,3,4,5};
         int *p1;
         int (*p2)[5];
         p1 = arr;
         p2 = &arr;
         printf("sizeof(arr) = %d\n", sizeof(arr)); //sizeof(arr) = 20
         printf("&arr = %d\n", &arr); //&arr = 6422276
         printf("arr = %d\n", arr); //arr = 6422276
         printf("&arr[0] = %d\n", &arr[0]); //&arr[0] = 6422276
         printf("sizeof(p1) = %d\n", sizeof(p1)); //sizeof(p1) = 4
         printf("p1 = %d\n", p1); //p1 = 6422276
         printf("*p1 = %d\n",*p1); //*p1 = 1
         printf("sizeof(p2) = %d\n", sizeof(p2)); //sizeof(p2) = 4
         printf("p2 = %d\n", p2); //p2 = 6422276
         printf("*p2 = %d\n", *p2); //*p2 = 6422276
         printf("**p2 = %d\n", **p2); //**p2 = 1
         printf("&arr + 1 = %d\n", &arr + 1); //&arr + 1 = 6422296
         printf("arr + 1 = %d\n", arr + 1); //arr + 1 = 6422280
         printf("&arr[0] + 1= %d\n", &arr[0] + 1); //&arr[0] + 1= 6422280
         printf("p1+ 1 = %d\n", p1 + 1); //p1+ 1 = 6422280
         printf("*(p1 + 1) = %d\n", *(p1 + 1)); //*(p1 + 1) = 2
         printf("p2 + 1 = %d\n", p2 + 1); //p2 + 1 = 6422296
         printf("*(p2 + 1) = %d\n", *(p2 + 1)); //*(p2 + 1) = 6422296
         printf("*p2 + 1 = %d\n", *p2 + 1); //*p2 + 1 = 6422280
         printf("**(p2 + 1) = %d\n", **(p2 + 1)); //**(p2 + 1) = 6422276
         printf("*(*p2 + 1) = %d\n", *(*p2 + 1)); //*(*p2 + 1) = 2

         return 0;
 }