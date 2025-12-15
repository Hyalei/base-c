#include <stdio.h>
#include <stdlib.h>


// 假设存储的元素是int
typedef int E;

typedef struct List {
    E *array;
    int capacity;
    int size;
} ArrayList;

int main(void) {
    ArrayList list1;
    ArrayList *list2 = malloc(sizeof(ArrayList));
    free(list2);
}
