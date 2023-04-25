// You will be given a string S as input contains only small English alphabets. You need to tell the number of vowels in it. The string will not contain any spaces.

// imput :ilikeassignments
// output : 6

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char sen[10000];
   scanf("%s",sen);
   int vow=0;

   for(int i=0;i<strlen(sen);i++){
    if(sen[i]=='a' || sen[i]=='e' || sen[i]=='i' || sen[i]=='o' || sen[i]=='u'){
        vow++;
    }
   }
   printf("%d",vow);
    return 0;
}
