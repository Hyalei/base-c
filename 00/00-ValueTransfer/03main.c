#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 10

typedef struct ElementType
{
    int key;
    char* value;
} ElementType;

// 定义数组类型
typedef ElementType* Array;

/// Create与Init的区别
/// Create函数需要修改调用者中的指针变量，因此必须以“指针的地址”作为实参；
/// 函数内部通常通过动态存储分配函数（如 malloc）申请存储空间，并将返回的首地址赋值给该指针的解引用，从而完成对象的创建。
/// @param array_ptr 数组首元素指针的地址
/// @param count 可变参数的数量
/// @param ... 可变参数
void CreateArray(Array* array_ptr, int count, ...)
{
    *array_ptr = malloc(ARRAY_MAX_SIZE * sizeof(ElementType));
    if (*array_ptr == NULL)
        return;
    if (count < 1 || count > ARRAY_MAX_SIZE)
        return;
    va_list args;
    va_start(args, count);
    for (int i = 0; i <= count - 1; i++)
    {
        (*array_ptr)[i] = va_arg(args, ElementType);
    }
    va_end(args);
}

/// 销毁数组
/// Create函数要与Destroy函数搭配使用，防止内存泄露
/// CreateArray中使用malloc函数返回的类型就是DestroyArray的入参类型
/// CreateArray函数中*array_ptr是Array类型
/// @param array
void DestroyArray(Array array)
{
    free(array);
}

///
/// @param array 数组首元素指针
/// @param count 可变参数的数量
/// @param ... 可变参数
void InitArray(ElementType* array, int count, ...)
{
    if (array == NULL)
        return;
    if (count < 1 || count > ARRAY_MAX_SIZE)
        return;
    va_list args;
    va_start(args, count);
    for (int i = 0; i <= count - 1; i++)
    {
        array[i] = va_arg(args, ElementType);
    }
    va_end(args);
}

void PrintArray(Array array)
{
    printf("[\n");
    for (int i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        printf("    %d ---> %s\n", array[i].key, array[i].value);
    }
    printf("]\n");
}

int main(int argc, char* argv[])
{
    Array array1;
    CreateArray(&array1, 3, (ElementType){1, "John"}, (ElementType){2, "Tom"}, (ElementType){3, "Joy"});
    PrintArray(array1);

    Array array2 = malloc(ARRAY_MAX_SIZE * sizeof(ElementType));
    InitArray(array2, 4, (ElementType){1, "XiaoHuang"}, (ElementType){2, "XiaoHong"}, (ElementType){3, "XiaoHei"}, (ElementType){4, "XiaoBai"});
    PrintArray(array2);
    DestroyArray(array2);
}
