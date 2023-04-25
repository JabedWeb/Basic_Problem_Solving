/**
Problem Statement

You will given an integer array A and the size N. You will also be given an integer value X. You need to tell how many times X was appeared in the array.

Input Format

First line will contain N.
Second line will contain the integer array A.
Third line will contain X.
Constraints

1 <= N <= 100
0 <= A[i] <= 1000; Here 0 <= i < N
0 <= X <= 1000
Output Format

Output the number of times X was appeared in the array.
Sample Input 0

6
4 3 5 3 3 5 
3
Sample Output 0

3
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int N,X;
    int count =0;
    scanf("%d",&N);

    int array[N];
    for(int i =0;i<N;i++){
        scanf("%d",&array[i]);
    }
    scanf("%d",&X);
    for(int i=0;i<N;i++){
        if(array[i]==X){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}