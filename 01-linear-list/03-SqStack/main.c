#include <stdio.h>
#include <stdlib.h>

#include "yans_book_defs.h"

// 栈的顺序存储表示

#define STACK_INIT_SIZE 100
#define STACK_INCREASEMENT 10

typedef struct SqStack
{
    ElemType* base;
    ElemType* top;
    int stack_size;
} SqStack;

typedef SqStack* SqStackPtr;

Status CreateStack(SqStackPtr* sq_stack_ptr_ptr)
{
    *sq_stack_ptr_ptr = malloc(sizeof(SqStack));
    (**sq_stack_ptr_ptr).base = malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if ((**sq_stack_ptr_ptr).base == NULL)
        return OVERFLOW;
    (**sq_stack_ptr_ptr).top = (**sq_stack_ptr_ptr).base;
    (**sq_stack_ptr_ptr).stack_size = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStackPtr sq_stack_ptr)
{
    free((*sq_stack_ptr).base);
    free(sq_stack_ptr);
}

Status InitStack(SqStackPtr sq_stack_ptr)
{
    if (sq_stack_ptr == NULL)
        return ERROR;
    (*sq_stack_ptr).base = malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if ((*sq_stack_ptr).base == NULL)
        return OVERFLOW;
    (*sq_stack_ptr).top = (*sq_stack_ptr).base;
    (*sq_stack_ptr).stack_size = STACK_INIT_SIZE;
}

Status ClearStack(SqStackPtr sq_stack_ptr)
{
    if (sq_stack_ptr == NULL)
        return ERROR;
    free((*sq_stack_ptr).base);
    (*sq_stack_ptr).base = (*sq_stack_ptr).top = NULL;
    (*sq_stack_ptr).stack_size = 0;
}

int main(int argc, char* argv[])
{
    SqStack sq_stack;
    InitStack(&sq_stack);
}
