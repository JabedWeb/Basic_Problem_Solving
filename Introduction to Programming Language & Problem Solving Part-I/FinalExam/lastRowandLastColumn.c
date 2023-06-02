/*
Problem Statement

You will be given a 2D matrix of N * M size. The matrix will contain integer value only. You need to print the values of last row and then print the values of last column.

*/




/*
Sample Input 

3 4
1 2 3 4
5 6 7 8
6 5 4 2


Sample Output 
6 5 4 2 
4 8 2 


*/


#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n,m;
    printf("Please enter the number\n");
    scanf("%d %d",&n ,&m);
    int matrix[n][m];


        //Read the matrix number 
    for(int i=0;i<n;i++ ){
        for(int j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    //show the matrix number 
    // for(int i=0;i<n;i++ ){
    //     for(int j=0;j<m;j++){
    //         printf("%d ",matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    //show the row number
    for(int i=0;i<m;i++ ){
        printf("%d ",matrix[n-1][i]);
    }
    printf("\n");
    //show the last column number
    for(int i=0;i<n;i++ ){
        printf("%d ",matrix[i][m-1]);
    }
    return 0;
}