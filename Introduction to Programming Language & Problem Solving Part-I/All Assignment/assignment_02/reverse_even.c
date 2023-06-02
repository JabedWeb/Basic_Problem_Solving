#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d",&N); 
    int array[N];
    for(int i=0;i<N;i++){
        scanf("%d",&array[i]);
    }
    for(int i=N-1;i>=0;i--){
        if(i%2==0){
            printf("%d\t",array[i]);
        }
    }
}
