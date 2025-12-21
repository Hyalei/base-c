#include <stdio.h>

typedef struct ElementType
{
    int key;
    int value;
} ElementType;

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
    printf("    value->%d\n", element.value);
    printf("}\n");
}

int main(int argc, char* argv[])
{
    ElementType element = {0, 10010};
    ElementType oldElement;
    GetElementValue(element, &oldElement);
    PrintElementValue(oldElement);
    ElementType newElement = {2, 33091};
    ChangeElementValue(&element, newElement);
    PrintElementValue(element);
}
