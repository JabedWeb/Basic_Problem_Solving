/*
Given the sum of four numbers and three of those numbers, find the missing number. All four numbers are positive integers.

*/

/**
Sample Input 1

3
20 2 4 1
15 5 5 5
30 10 5 3
Sample Output 1

13
0
12
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    // Take input for the number of test cases
    scanf("%d", &n);

    int sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        int total;
        // Take input for the total sum of numbers
        scanf("%d", &total);

        for(int j = 1; j <= 3; j++) {
            int num;
            // Take input for three numbers
            scanf("%d", &num);
            sum = sum + num;
        }

        // Calculate the difference between the total sum and the sum of three numbers
        int dif = total - sum;
        printf("%d\n", dif);    
    }
    return 0;
}
