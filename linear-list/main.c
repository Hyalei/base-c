#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

/**
 *
 * @param x
 * @param y
 * @param function
 * @return
 */
int calc(int x, int y, int (*function)(int, int)) {
    return function(x, y);
}



int main() {
    int r1 = calc(3, 2, add);  // 传入 add
    int r2 = calc(3, 2, sub);  // 传入 sub

    printf("%d\n", r1);  // 5
    printf("%d\n", r2);  // 1

    return 0;
}

