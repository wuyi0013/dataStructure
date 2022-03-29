#include<stdio.h>
typedef struct student{
    int id;
    char name[20];
    char sex;
}stu;
int main () {
    stu s;
    scanf("%d%s %c",&s.id,s.name,&s.sex);
    printf("%d %s %c",s.id,s.name,s.sex);
    return 0;
 }