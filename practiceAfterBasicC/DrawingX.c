
/*
Some day, an artist wanted to draw an X mark on the wall in a fashionable way.

He wanted to do so by grouping snippets of slashes /, backslashes \, asterisks * and a capital X letter in an N×N
 square as shown in the sample. Can you help him?

Input
Only one line containing one odd number N(3≤N≤49).

Output
Print the fashionable drawing.

Example
inputCopy
5
outputCopy

\***/
*\*/*
**X**
*/*\*
/***\
 
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
  int n;
  double data;
  scanf("%d",&n);

    data =ceil((double)n/2);
    printf("The output %.f\n",data);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==data && j==data){
            printf("X");
        }
        else if(i==j){
          printf("\\");
        }
        else if (i+j==n+1){
          printf("/");
        }
        else {
          printf("*");
        }
    }
    printf("\n");
  }

    return 0;
}
