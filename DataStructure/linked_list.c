#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
}Node;

Node* initList(void){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
int insert_head(Node *L, ElemType e){
    Node *new_elem = (Node*)malloc(sizeof(Node));
    new_elem->data = e;
    new_elem->next = L->next;
    L->next = new_elem;
    return 1;
}

//遍历+获取长度
int list_node(Node *L){
    int len = 0;
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d-", p->data);
        p = p->next;
        len++;
    }
    printf("\nlength:%d\n", len);
    return len;
}

//获取尾节点
Node* get_tail(Node *L){
    Node *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

//尾插法
Node* insert_hail(Node *L, ElemType e){
    Node *new_node = initList();
    Node *L_hail = get_tail(L);
    new_node->data = e; 
    L_hail->next = new_node;
    return new_node;
}

//中间插入
int insert_middle(Node *L, short position, ElemType e){

}

//删除节点
int delete_node(Node *L, short position){

}

//释放列表
void free_node(Node *L){

}

int main(void){
    Node *list_1 = initList();
    for(int i = 0; i < 5; i++){
        insert_hail(list_1, 10 + i);
    }
    list_node(list_1);
    return 0;
}
