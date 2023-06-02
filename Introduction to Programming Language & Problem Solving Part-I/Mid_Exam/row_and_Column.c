/**
Problem Statement

You will be given two positive integer N and K. You need to print from 1 to N, and you need to do this K times.

Please look at the sample input output.

Input Format

Input will contain N and K.
Constraints

1 <= N,K <= 100
Output Format

You need to print fron 1 to N, K times. Don't forget to print new line after printing from 1 to N.
Sample Input 0

10 5
Sample Output 0

1 2 3 4 5 6 7 8 9 10 
1 2 3 4 5 6 7 8 9 10 
1 2 3 4 5 6 7 8 9 10 
1 2 3 4 5 6 7 8 9 10 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int row,column;
    scanf("%d %d",&column,&row);
    for(int i=1;i<=row;i++){
        for(int j=1;j<=column;j++){
            printf("%d\t",j);
        }
        printf("\n");
    }   
    return 0;
}