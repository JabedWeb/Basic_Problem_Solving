/*

Problem Statement

You will be given three non-negative integers A,B and C. You need to tell if these integers form an equilateral triangle (A triangle whose three sides are the same and each side contains a positive value). If the answer is yes, print "Yes" otherwise "No".

Input Format

Input will contain A,B and C.
Constraints

0 <= A,B,C <= 100
Output Format

Output "Yes" or "No" without quotation.
Sample Input 0

2 4 2
Sample Output 0

No

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    if(A>0 && B>0 && C>0 && A==B && B==C){
        printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}