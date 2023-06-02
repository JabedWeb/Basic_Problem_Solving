/*

You are given N
 numbers, and you should divide them into consecutive groups of size K
, then print the minimum among each group. If the last group is of size <K
, print the minimum number found just after the last number received.

For more explanation, see the notes.

Input
First line contains two numbers N,K
 (1≤K≤N≤105
) – the number of values, and the range length after which you should print the minimum.

Second line contains N
 numbers (−109≤x≤109
).

Output
Print the answer in a single line.

Examples
inputCopy
8 3
4 -1 2 3 5 0 2 7
outputCopy
-1 0 2 


*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
int main() {
    int n,k;
    printf("Please enter the number\n");
    scanf("%d %d",&n,&k);
        int array[n];
    for(int i=1;i<=n;i++){
        scanf("%d",&array[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",array[i]);
    }
    int firstDataGroup=1;
    double total = ceil((double)n / k);
    printf("\nthe total number %.f\n",total);
    for(int i =1;i<=total;i++){
        int minimumValue=INT_MAX;
        for(int j=firstDataGroup;j<=firstDataGroup+k-1 && j <= n;j++){
            if(minimumValue>array[j]){
                minimumValue=array[j];
            }
           // printf("minimum %d %d\n",minimumValue,array[j]);
        }
        printf("%d ",minimumValue);
        firstDataGroup=firstDataGroup+k;
        // printf("First Group %d\n",firstDataGroup);
    }
    return 0;
}