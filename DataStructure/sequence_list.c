#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    int ISBN;
    char name[20];
    unsigned short price;
}Book;

typedef struct{ 
    ElemType data[MAXSIZE];
    int length;
}SeqLIst;

void Create_Book(Book *book, int ISBN, char *name, unsigned short price){
    book->ISBN = ISBN;
    strcpy(book->name, name);
    book->price = price;
}

Book* Create1_Book(int ISBN, const char *name, unsigned short price) {
    // 1. 动态分配内存
    Book *book = (Book*)malloc(sizeof(Book));
    if (book == NULL) {
        fprintf(stderr, "Error: malloc failed in Create_Book!\n");
        return NULL;  // 分配失败，返回 NULL
    }

    // 2. 赋值
    book->ISBN = ISBN;
    
    // 安全复制字符串：防止缓冲区溢出
    strncpy(book->name, name, sizeof(book->name) - 1);
    book->name[sizeof(book->name) - 1] = '\0';  // 确保以 \0 结尾

    book->price = price;

    // 3. 返回指针
    return book;
}
//创建顺序表
SeqLIst* Create_List(void){
    SeqLIst *list = malloc(sizeof(SeqLIst));
    list->length = 0;
    return list;
}
//尾部添加
int append_elem(SeqLIst *L, ElemType e){
    if(L->length >= MAXSIZE){
        printf("sequence list has reached its limit.\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    //printf("The data has been appended to the list.\n");
    //printf("length: %d;element:%d\n", L->length, L->data[L->length-1]);
    return 1;
}
//遍历
void list_elem(SeqLIst *L){
    for(int i = 0; i < L->length; i++){
        printf("-%d-", L->data[i]);
    }
    printf("\n");
}
//插入!!!!
int insert_elem(SeqLIst *L, short position, ElemType data){
    if(L->length >= MAXSIZE){
        printf("List elements have reached its limit.\n");
        return 0;
    }
    else if(position > L->length || position <= 0){
        printf("A wrong position.");
        return 0;
    }
    else if(position > 0 && position <= L->length){
        for(int i = L->length - 1; i >= position + 1; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[position-1] = data;
        L->length++;
        printf("the element has been inserted.\n");
        return 1;
    }
    else{
        printf("error!");
        return 0;
    }
}

//删除元素
int delete_elem(SeqLIst *L, short position){
    if(L->length == 0){
        printf("List is empty.");
        return 0;
    }
    else if(position <= 0 || position > L->length){
        printf("The position has no element.");
    }
    else if(position > 0 && position <= L->length){
        for(int i = position; i < L->length; i++){
            L->data[i-1] = L->data[i];
        }
        L->length--;
        return 1;
    }
}
int main(void){
    Book *book1 = malloc(sizeof(Book));
    Create_Book(book1, 123456, "DataStructure", 99);
    Book *book2 = Create1_Book(123457, "C_syntax", 69);
    printf("%d-%s-%d\n", book1->ISBN, book1->name, book1->price);
    printf("%d-%s-%d\n", book2->ISBN, book2->name, book2->price);
    printf("-----------------------------------\n");
    free(book1);
    SeqLIst *list_1 = Create_List();
    for(short i = 0; i < 20; i++){
        append_elem(list_1, i+20);
    }
    list_elem(list_1);
    insert_elem(list_1, 1, 666);
    list_elem(list_1);
    delete_elem(list_1, 1);
    list_elem(list_1);
    free(list_1);
    return 0;
}
