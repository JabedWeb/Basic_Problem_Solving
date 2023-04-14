#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d",&N); 
    int data;
    int sum_even=0;  
    int sum_odd=0; 
    for(int i=1;i<=N;i++){
        scanf("%d",&data);
        if(data%2==0){
            sum_even+=data;
        }
        else{
            sum_odd+=data;
        }
    } 
    printf("%d",sum_even);
    printf("\t");
    printf("%d",sum_odd);
    return 0;
}
