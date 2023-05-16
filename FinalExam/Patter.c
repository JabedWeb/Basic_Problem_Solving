/*
Write a C program that will take an integer N and creates this pattern for the corresponding inputs.

*/



/*
Sample Input 1

3

Sample Output 1
  ^
 ***
^^^^^
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    int k=1;

    scanf("%d",&n);
    int s=n-1;

    for(int i=1;i<=n;i++){
        if(i%2==0){
            //print spaces;
            for(int j=1;j<=s;j++){
                printf(" ");
            }    
                //print star
            for(int j=1;j<=k;j++){
                printf("*");
            }
            k=k+2;
            s--;
        }
        else {
                        //print spaces;
            for(int j=1;j<=s;j++){
                printf(" ");
            }    
                //print arrow
            for(int j=1;j<=k;j++){
                printf("^");
            }

            k=k+2;
            s--;
        }
        printf("\n");
    
    }
    return 0;
}