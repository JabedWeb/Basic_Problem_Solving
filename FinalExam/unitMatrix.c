/*
Problem Statement
You will be given a matrix of size N * N. You need to tell if it is unit matrix or not.

Note: A matrix is called a unit matrix if all the primary diagonal elements are 1 and all the non-diagonal elements are 0.

*/


/*

Sample Input 0
3
1 0 0
0 1 0
0 0 1


Sample Output 0
YES



*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    int flag=1;
    printf("Please enter the number\n");
    scanf("%d",&n);
    int matrix[n][n];


    //Read the matrix number 
    for(int i=0;i<n;i++ ){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    //show the matrix number 
    for(int i=0;i<n;i++ ){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }


    //check the unit matrix 
    for(int i=0;i<n;i++ ){
        for(int j=0;j<n;j++){
            // check all non-diagonal elements 
            if(i!=j){
                if(matrix[i][j]==0){
                    continue; // if elements are zero then continue
                }
                else {
                    flag=0; //if elements are not zero then flag value equal to zero that means we get non-zero elements
                }
            }

            // diagonal elements check
            else if (i==j){
                if(matrix[i][j]==1){ //if diagonal elements are 1 then it continue 
                    continue;
                }
                else {
                    flag=0; // if diagonal elemets are not 1 that means its not a unit matrix 
                }
            }
        }
    }

    if(flag==1){
        printf("YES");
    }
    else{
        printf("N0");
    }




    return 0;
}