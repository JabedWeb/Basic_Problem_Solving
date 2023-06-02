/**
You will be given a string S. The string will contain both small and capital English alphabets only. You need to tell how many of them are capital alphabets and how many are small alphabets.

Input Format

Input will contain only S.
Constraints

1 <= |S| <= 1000; Here |S| means the length of S.
Output Format

Output the count of capital alphabets first, then the count of small alphabets
Sample Input 0

tHeBRoWnFoX
Sample Output 0

6 5
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char sen[1000];
    int count[2]={0};
    scanf("%s",sen);
    for(int i=0;i<strlen(sen);i++){
         if(sen[i]>='a' && sen[i]<='z'){
            count[0]++;
         }
         else if(sen[i]>='A' && sen[i]<='Z'){
            count[1]++;
         }
    }
    printf("%d\t",count[1]);
    printf("%d\t",count[0]);

    return 0;
}
