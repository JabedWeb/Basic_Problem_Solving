/*
Problem Statement

There are N army people standing in a line. Their major ordered them to make a line in asceding order according to their age. And then the major called the person stading in the middle. If there are two people in the middle then he will call both of them. Can you tell the age of the middle man or men?


*/



/*

Sample Input 0

6
20 30 10 50 40 60

Sample Output 0

30 40


*/


#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    printf("Please enter the number\n");
    scanf("%d",&n);
    int men[n];

    for(int i=0;i<n;i++){
        scanf("%d",&men[i]);
    }

    for(int i=0;i<n;i++){
        printf("%d ",men[i]);
    }
    printf("\n");

    //ascending order with selection sort

    for(int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if(men[i]>men[j]){
                int tem=men[i];
                men[i]=men[j];
                men[j]=tem;
            }
        }
    }


    // if the men count is even number
     
    if(n%2==0){
        printf("%d %d",men[(n-1)/2], men[((n-1)/2)+1] );
    }
    // men count is odd number
    else{
        printf("%d",men[n/2]);
    }



    return 0;
}