#include <stdio.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d",&N); 
    int X,V;
    int array[N];
    for(int i=0;i<N;i++){
        scanf("%d",&array[i]);
    }

    scanf("%d",&X);
    scanf("%d",&V);
    array[X]=V;


    for(int i=N-1;i>=0;i--){
        printf("%d\t",array[i]);
    }
    return 0;
}
