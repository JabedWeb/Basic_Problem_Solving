#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d",&N);

    if(N<=0){
        for(int i=N;i<=1;i++){
            printf("%d\t",i);
        }
    }else{
       for(int i=1;i<=N;i++){
            printf("%d\t",i);
        }
    }

    return 0;
}