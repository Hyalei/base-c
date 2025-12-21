#include <stdio.h>
#include <stdlib.h>

#include "yans_book_defs.h"

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

Status InitList_Link(LinkList list_ptr)
{
    if (list_ptr == NULL)
        return ERROR;
    list_ptr->next = NULL;
    return OK;
}

int main(void)
{
    LNode node;
    InitList_Link(&node);
    printf("hello world");
}

// int main(void)
// {
//     // 常见错误
//     // 只声明了一个结构体指针而没有声明结构体，栈中只分配的存储指针的内存，而没有存储结构体的内存。
//     // 为初始化的指针指向未知内存，导致后续方法通过该指针访问结构体时报错：EXC_BAD_ACCESS
//     LinkList list_ptr;
//     InitList_Link(list_ptr);
//     printf("hello world");
// }
