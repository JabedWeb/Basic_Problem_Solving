#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        // Print spaces
        for (int j = i; j < N; j++) {
            printf("  ");
        }
        // Print numbers
        int num = 1;
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        for (int j = 1; j < i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    for (int i = N - 1; i >= 1; i--) {
        // Print spaces
        for (int j = i; j < N; j++) {
            printf("  ");
        }
        // Print numbers
        int num = 1;
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        for (int j = 1; j < i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
