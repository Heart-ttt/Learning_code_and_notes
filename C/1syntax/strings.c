#include <stdio.h>
#include <string.h>


int main(void){
    char dest[20];
    char src[] = "hello";
    printf("%c\n", src[5]);
    strncpy(dest, src, 6);
    //dest[4] = '\0';
    printf("%s", dest);
    return 0;
}
