#include <stdio.h>

void addOne(int x) {
    x = x + 1;
    printf("Inside, x = %d\n", x);
}

void addOneRef(int *x) {
     *x = *x + 1;
    printf("Inside ref, x = %d\n", *x);
}

int main() {
    int a = 10;
    
    printf("Before , a = %d\n", a);
    addOne(a);
    printf("After , a = %d\n", a);
    
    printf("Before ref , a = %d\n", a);
    addOneRef(&a);
    printf("After ref , a = %d\n", a);
    
    return 0;
}
