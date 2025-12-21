#include <stdio.h>
#include <stdlib.h>
#include "yans_book_defs.h"


#define LIST_INIT_SIZE 3 //线性表存储空间的初始分配量
#define LIST_INCREMENT 10 // 线性表存储空间的分配增量

typedef struct SqList
{
    ElemType* elem; // 存储空间基址（数组首地址）
    int length; // 当前长度
    int list_size; // 当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;

Status InitList_Sq(SqList* list_ptr)
{
    if (list_ptr == NULL)
        return ERROR;
    list_ptr->elem = malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (list_ptr->elem == NULL)
        return ERROR;
    list_ptr->length = 0;
    list_ptr->list_size = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList* L, int index, ElemType e)
{
    if (L == NULL)
        return ERROR;
    // i的合法范围是[1,length+1]，所以i的非法范围是(负无穷, 1)和(length+1,正无穷)
    if (index < 1 || index > L->length + 1)
    {
        return ERROR;
    }
    // 当length+1大于数组长度时，扩容数组
    if (L->length + 1 > L->list_size)
    {
        ElemType* newElem = realloc(L->elem, (L->length + LIST_INCREMENT) * sizeof(ElemType));
        if (newElem == NULL)
        {
            exit(OVERFLOW);
        }
        L->elem = newElem;
        L->list_size += LIST_INIT_SIZE;
    }
    for (int i = L->length; i >= index - 1; i--)
    {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[index - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete_Sq(SqList* L, int index, ElemType* e)
{
    if (L == NULL)
        return ERROR;
    if (index < 1 || index > L->length)
    {
        return ERROR;
    }
    *e = L->elem[index - 1];
    for (int i = index - 1; i <= L->length - 1; i++)
    {
        L->elem[i] = L->elem[i + 1];
    }
    L->length--;
    return OK;
}

Status DestroyList_Sq(SqList* L)
{
    if (L == NULL)
        return ERROR;
    free(L->elem);
    L->elem = NULL;
    free(L);
    L = NULL;
    return OK;
}

void PrintList(const SqList* L)
{
    if (L == NULL)
        return;
    for (int i = 0; i <= L->length - 1; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

// int main(void) {
//     SqList *sq_list_ptr = malloc(sizeof(SqList));
//     InitList_Sq(sq_list_ptr);
//     ListInsert_Sq(sq_list_ptr, 1, 1);
//     ListInsert_Sq(sq_list_ptr, 1, 2);
//     ListInsert_Sq(sq_list_ptr, 1, 3);
//     ListInsert_Sq(sq_list_ptr, 1, 4);
//     ElemType e;
//     ListDelete_Sq(sq_list_ptr, 1, &e);
//     printf("Deleted element: %d\n", e);
//     PrintList(sq_list_ptr);
//     DestroyList_Sq(sq_list_ptr);
// }

int main(void)
{
    SqList sq_list;
    InitList_Sq(&sq_list);
    ListInsert_Sq(&sq_list, 1, 1);
    ListInsert_Sq(&sq_list, 1, 2);
    ListInsert_Sq(&sq_list, 1, 3);
    ListInsert_Sq(&sq_list, 1, 4);
    ElemType e;
    ListDelete_Sq(&sq_list, 1, &e);
    printf("Deleted element: %d\n", e);
    PrintList(&sq_list);
    // DestroyList_Sq(&sq_list);
}
