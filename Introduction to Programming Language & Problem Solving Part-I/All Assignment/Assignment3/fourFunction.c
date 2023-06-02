#include <stdio.h>

int square(int num) {
    return num * num;
}

int get_value() {
    return 42;
}

void print_string(char str[]) {
    printf("The string is: %s\n", str);
}

void sub_cal() {
    int x = 10;
    int y = 5;
    int result = x - y;
    printf("%d\n", result);
}

int main() {
    // Example 1:
    int x = 5;
    int x_squared = square(x);
    printf("%d squared is %d\n", x, x_squared);
    
    // Example 2:
    int value = get_value();
    printf("The value is: %d\n", value);
    
    // Example 3:
    char str[] = "Hello, world!";
    print_string(str);
    
    // Example 4:
    sub_cal();
    
    return 0;
}
