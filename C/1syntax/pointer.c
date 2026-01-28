#include <stdio.h>

void fun1(void){
    int a=5;
    int *p = &a;
    printf("p所指向的地址：%d\n",p);
    printf("p所指向地址的值：%d\n",*p);
    *p = 100;
    printf("修改后的a的值：%d\n",*p);
}

void swap(int *param1,int *param2){
      int temp = *param1;
      *param1 = *param2;
      *param2 = temp;
}

int main(void) {
    int a = 3;
    int b = 5;
    swap(&a, &b);
    printf("a = %d, b = %d", a, b);
    return 0;
}
