#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    char* name;
    int age;
} Item;

typedef struct Label
{
    char* comment;
    int type;
} Label;

typedef struct ElementType
{
    int key;
    char* str;
    Item struct_member;
    Label* pointer_member;
} ElementType;

typedef ElementType* ElementPtr;


void CreateElement(ElementPtr* element_ptr_ptr, int key, char* str, Item value, Label* pointer_member)
{
    *element_ptr_ptr = malloc(sizeof(ElementType));
    if (*element_ptr_ptr == NULL)
        return;
    // 基本数据类型直接拷贝
    (*element_ptr_ptr)->key = key;

    // 字符串需要深拷贝
    (*element_ptr_ptr)->str = malloc(strlen(str) + 1);
    if ((*element_ptr_ptr)->str == NULL)
        return;
    /*
     * 注意 *(*element_ptr_ptr)->str = *str;的结果是只拷贝了第一个字符
     * strcpy((*element_ptr_ptr)->str, str);的结果是拷贝了整个字符串
     * 两者并不等价
     */
    strcpy((*element_ptr_ptr)->str, str);

    // 结构体成员直接拷贝
    (*element_ptr_ptr)->struct_member = value;
    (*element_ptr_ptr)->struct_member.name = malloc(strlen(value.name) + 1);
    if ((*element_ptr_ptr)->struct_member.name == NULL)
        return;
    strcpy((*element_ptr_ptr)->struct_member.name, value.name);

    // 指针成员需要深拷贝
    (*element_ptr_ptr)->pointer_member = malloc(sizeof(Label));
    if ((*element_ptr_ptr)->struct_member.name == NULL)
        return;
    *((*element_ptr_ptr)->pointer_member) = *pointer_member;
    (*element_ptr_ptr)->pointer_member->comment = malloc(strlen(pointer_member->comment) + 1);
    if ((*element_ptr_ptr)->struct_member.name == NULL)
        return;
    strcpy((*element_ptr_ptr)->pointer_member->comment, pointer_member->comment);

    /*
     * 可以看出来指针类型（包含字符串类型）的成员需要深拷贝
     */
}

void DestroyElement(ElementPtr element_ptr)
{
    if (element_ptr == NULL)
        return;
    free(element_ptr->str);
    free(element_ptr->struct_member.name);
    free(element_ptr->pointer_member->comment);
    free(element_ptr->pointer_member);
    free(element_ptr);
}

void InitElement(ElementPtr element_ptr, int key, char* str, Item value, Label* pointer_member)
{
    if (element_ptr == NULL)
        return;
    // 基本数据类型直接拷贝
    element_ptr->key = key;

    // 字符串需要深拷贝
    element_ptr->str = malloc(strlen(str) + 1);
    if (element_ptr->str)
        return;
    /*
     * 注意 element_ptr->str = *str;的结果是只拷贝了第一个字符
     * strcpy(element_ptr->str, str);的结果是拷贝了整个字符串
     * 两者并不等价
     */
    strcpy((element_ptr)->str, str);

    // 结构体成员直接拷贝
    element_ptr->struct_member = value;
    element_ptr->struct_member.name = malloc(strlen(value.name) + 1);
    if (element_ptr->struct_member.name == NULL)
        return;
    strcpy(element_ptr->struct_member.name, value.name);

    // 指针成员需要深拷贝
    element_ptr->pointer_member = malloc(sizeof(Label));
    if (element_ptr->pointer_member == NULL)
        return;
    *(element_ptr->pointer_member) = *pointer_member;
    element_ptr->pointer_member->comment = malloc(strlen(pointer_member->comment) + 1);
    if (element_ptr->pointer_member->comment == NULL)
        return;
    strcpy(element_ptr->pointer_member->comment, pointer_member->comment);
}

void ClearElement(ElementPtr element_ptr)
{
    if (element_ptr == NULL)
        return;
    free(element_ptr->str);
    free(element_ptr->struct_member.name);
    free(element_ptr->pointer_member->comment);
    free(element_ptr->pointer_member);
}

int main(int argc, char* argv[])
{
    ElementPtr element_ptr1;
    Label label = {"I Agree", 1};
    CreateElement(&element_ptr1, 1, "Safety", (Item){"Anna", 28}, &label);
    DestroyElement(element_ptr1);


    ElementType* element_ptr2 = malloc(sizeof(ElementType));
    InitElement(element_ptr2, 2, "Safety", (Item){"Anna", 28}, &label);
    ClearElement(element_ptr2);
    free(element_ptr2);


    ElementType element;
    InitElement(&element, 3, "Safety", (Item){"Anna", 28}, &label);
    ClearElement(&element);
}
