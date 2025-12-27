#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef ElementType* ElementPtr;

void CreateElement(ElementPtr* element_ptr_ptr, ElementType value)
{
    *element_ptr_ptr = malloc(sizeof(ElementType));
    if (*element_ptr_ptr == NULL)
        return;
    **element_ptr_ptr = value;
}

void DestroyElement(ElementPtr element_ptr)
{
    free(element_ptr);
}

void InitElement(ElementPtr element_ptr, ElementType value)
{
    if (element_ptr == NULL)
        return;
    *element_ptr = value;
}

void GetElementValue(ElementType element, ElementType* elementPtr)
{
    // 不要将下行改为 elementPtr = &element;
    // 这个方法中的element是方法内的局部变量，方法结束后，此变量所在内存就会被回收，所以elementPtr指向element的地址没有意义。
    *elementPtr = element; // 将element拷贝到elementPtr所指的内存
}

void ChangeElementValue(ElementType* elementPtr, ElementType newElement)
{
    *elementPtr = newElement;
}

void PrintElementValue(ElementType element)
{
    printf("%d\n", element);
}

int main(int argc, char* argv[])
{
    ElementType element = 10;
    ElementType oldElement;
    GetElementValue(element, &oldElement);
    PrintElementValue(oldElement);
    ElementType newElement = 200;
    ChangeElementValue(&element, newElement);
    PrintElementValue(element);
    if (&element != &newElement)
        printf("element和newElement的存储地址不同\n");
    else
        printf("element和newElement的存储地址相同\n");
}
