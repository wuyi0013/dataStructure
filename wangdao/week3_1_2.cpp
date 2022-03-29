#include<stdio.h>
int main(){
   int sum=0;
   for(int i=1;i<=10;i++)
   {
       for(int j=1;j<=20;j++)
       {
           for(int m=1;m<=50;m++)
           {
                for(int k=1;k<=100;k++)
                {
                    if(10*i+5*j+2*m+k==100&&i+j+k+m==40)
                    {
                        sum++;
                        //printf("%d %d %d %d\n",i,j,m,k);
                    }    
                }
           }
       }
   }
   printf("%d",sum);
}