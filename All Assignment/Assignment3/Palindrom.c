#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    scanf("%s", str);
    if (is_palindrome(str)) {
        printf("palindrome.\n");
    } else {
        printf( "not palindrome.\n");
    }
    return 0;
}
