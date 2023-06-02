/*

Problem Statement

You will be given a string S consisting of small alphabets, capital alphabets and spaces. You need to count number of small alphabets, capital alphabets and spaces in the string S.*/


/*

Sample Input 0

Hello Everyone
Sample Output 0

Capital - 2
Small - 11
Spaces - 1

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int count[3]={0}; // initialize count array to store number of capital ,small ,spaces 
    char sen[1000];


    // as take input with spaces ,so let's take fgets
    fgets(sen,1000,stdin);

    for(int i=0;i<strlen(sen);i++){
        if(sen[i]>='A' && sen[i] <='Z'){
            count[0]++;//increment the count for the capital
        }
        else if(sen[i]>='a' && sen[i] <='z'){
            count[1]++; //increment the count for the small
        }
        else {
            count[2]++; //increment the count for the spaces
        }
    }

    printf("Capital - %d\n",count[0]);
    printf("Small - %d\n",count[1]);
    printf("Spaces - %d\n ",count[2]);
    return 0;
}