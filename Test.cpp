#include <stdio.h>
void my_int_func(int x) {
    printf("%d\n", x);
}

void print2(void (*foo)(int)) {
    foo(2);
}

int main() {
    print2(&my_int_func);
    return 0;
}