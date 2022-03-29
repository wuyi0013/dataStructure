#include <stdio.h>
#include <stdlib.h>
void fun(int i)
{
    if (i < 0)
    {
        //return 2;
        exit(1);
    }
    else
    {
        //return 5;
        exit(0);
    }
}
int main()
{
    int a, b;
    scanf("%d", &a);
    
    b = 1;
    /*if (fun(a))
    {
        printf("%d", b);
    }
    else
    {
        printf("nonono");
    }12
    system("pause");
    return 0;*/
    //printf("%d",fun(a));
   // fun(a);
     printf("nonono");
    system("pause");
    return 0;
}