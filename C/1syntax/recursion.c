# include <stdio.h>

int fun1(int n) {
    if (n <= 1) {
        return 1;
    } 
    else {
        return n * fun1(n - 1);
    }
}

int main(void){
    int a = fun1(3);
    printf("number=%d", a);
    return 0;
}
