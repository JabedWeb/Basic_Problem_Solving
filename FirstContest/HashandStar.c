/*

Problem Statement

Write a C program that will take an positive Odd integer N and create this pattern for the corresponding inputs. See the sample input output for understanding the pattern.

Input Format

You will be given a positive Odd integer N as input.
Constraints

1 <= N <= 21
Output Format

Output the pattern
Sample Input 0

7
Sample Output 0

***#***
***#***
***#***
#######
***#***
***#***
***#***



*/


#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    printf("Please enter the number\n");
    scanf("%d",&n);

    // double mid=((double)n+1)%2.0;
    int mid = (n + 1) / 2;

    for (int i =1;i<=n;i++){
        if (i==mid){
             for(int j=1;j<=n;j++){
              printf("#");
            }
        }
        else {
        for(int j=1;j<=n;j++){
            if(j==mid){
                printf("#");
            }
            else {
                printf("*");
            }
        }
        }

        printf("\n");
    }
    return 0;
}