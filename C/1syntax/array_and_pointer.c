#include <stdio.h>
#include <stdlib.h>

int a[] = {1, 2, 3, 4, 5};


void fun1(const int *arr){
    const int *p;
    p = arr;
    printf("%p\n", arr);
    printf("%p\n", p);
    printf("%d\n", *(p+1));
}

typedef int arr_type;

//在堆内存中开辟一片空间来存放数组
arr_type* Create_arr(int len){
    arr_type *arr = malloc(sizeof(arr_type)*len);
    return arr;
}

int main(void){
     //fun1(a);
    int *arr_1 = Create_arr(5);
    *(arr_1+4) = 3;
    return 0;
}
