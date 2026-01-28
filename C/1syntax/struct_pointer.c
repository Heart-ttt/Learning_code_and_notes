#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
};

typedef struct
{
    char stuId[11];
    char stuName[20];
    int age;
}student;

struct point CreatePoint(int a, int b){
    struct point p;
    p.x = a;
    p.y = b;  
    return p; 
}

void inital_stu(student *stu,const char *Id, const char *Name, int age){
    strcpy(stu->stuId, Id);
    strcpy(stu->stuName, Name);
    stu->age = age;
    printf("%s-%s-%d\n", stu->stuId, stu->stuName, stu->age);
}

int main(void){
    struct point space = CreatePoint(3,4);
    student LiMIng;
    student *WangDa = (student*)malloc(sizeof(student));
    inital_stu(WangDa, "2022406449", "WangDa", 21);
    inital_stu(&LiMIng, "2022406450", "LiMing", 20);
    free(WangDa);
    printf("%d,%d", space.x, space.y);
}
