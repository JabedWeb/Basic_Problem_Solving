// You will be given an integer array A of size N. You need to count the number of even elements and the number of odd elements in the array and print them.

//input 
// 3
// 7 3 10 
// output
// 1 	2 	

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int count[2]={0};
    int array[n];

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

        for(int i=0;i<n;i++){
            if(array[i]%2==0){
                count[0]++;
            }
            else {
                count[1]++;
            }
    }
    printf("%d\n",count[0]);
    printf("%d\t",count[1]);

   
    return 0;
}