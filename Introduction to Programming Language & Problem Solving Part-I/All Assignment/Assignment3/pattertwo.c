#include <stdio.h>

int main() {
    int N;
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        // Print spaces
        for (int j = i; j < N; j++) {
            printf("  ");
        }
        // Print numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
