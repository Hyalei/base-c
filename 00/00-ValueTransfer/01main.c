#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementType
{
    int key;
    char* value;
} ElementType;

typedef ElementType* ElementPtr;

void CreateElement(ElementPtr* element_ptr_ptr, int key, char* value)
{
    *element_ptr_ptr = malloc(sizeof(ElementType));
    (*element_ptr_ptr)->key = key;
    (*element_ptr_ptr)->value = malloc(strlen(value) + 1);
    strcpy((*element_ptr_ptr)->value, value);
}

void DestroyElement(ElementPtr element_ptr)
{
    if (element_ptr == NULL)
        return;
    free((*element_ptr).value);
    free(element_ptr);
}

void InitElement(ElementPtr element_ptr, int key, char* value)
{
    if (element_ptr == NULL)
        return;
    // element_ptr->key = key;这行代码和(*element_ptr).key = key;等价，是一种简便写法，相当于->隐式解指针了
    (*element_ptr).key = key;
    (*element_ptr).value = malloc(sizeof(value) + 1);
    strcpy((*element_ptr).value, value);
}

void ClearElement(ElementPtr element_ptr)
{
    if (element_ptr == NULL)
        return;
    free((*element_ptr).value);
}

void GetElementValue(ElementType element, ElementType* elementPtr)
{
    *elementPtr = element;
}

void ChangeElementValue(ElementType* elementPtr, ElementType newValue)
{
    *elementPtr = newValue;
}

void PrintElementValue(ElementType element)
{
    printf("{\n");
    printf("    key->%d\n", element.key);
    printf("    value->%s\n", element.value);
    printf("}\n");
}

int main(int argc, char* argv[])
{
    ElementType element = {0, "Spring"};
    ElementType oldElement;
    GetElementValue(element, &oldElement);
    PrintElementValue(oldElement);

    ElementType newElement = {2, "Fall"};
    ChangeElementValue(&element, newElement);
    PrintElementValue(element);

    ElementPtr element_ptr;
    CreateElement(&element_ptr, 1, "Summer");
    DestroyElement(element_ptr);

    ElementType element1;
    InitElement(&element1, 3, "Winter");
    ClearElement(&element1);
}
