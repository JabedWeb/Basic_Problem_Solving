/*
Problem Statement

You are given a list of numbers. Now find the position of a specific number from the list; if the number is not found in the given list then you have to print Not Found.

Note: Find the first occurence of that number from left.

Input Format

Input starts with an integer T, denoting the number of test cases.
Next line contains N, size of the list.
Next line contains N, values of the list.
Last integer contains S, the number that you need to find.
Constraints

1 <= T <=20
1 <= N <=1000
1 <= S <=1000
Output Format

For each test case you have to print “Case T: R” (except quotes) where T is the test case and R is the position of the S from N integers. If S is not found in the given N integers then you have to print “Case T: Not Found” in a line.

Note: Don't forget to print a new line;

Sample Input 0

3
5
8 5 2 10 9 
10
3
50 20 60 
20
4 
1 2 2 4 
5
Sample Output 0

Case 1: 4
Case 2: 2
Case 3: Not Found


*/

#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    printf("Please enter the number\n");
    scanf("%d",&n);

    for(int i =1;i<=n;i++){
        int countList=0;
        int count =0;
        scanf("%d",&countList);
        // printf("\nCountlist =%d\n",countList);
        int array[countList];
        for(int j=1;j<=countList;j++){
            scanf("%d",&array[j]);
        }
        int search;
        scanf("%d",&search);

        for(int j=1;j<=countList;j++){
            if(array[j]==search){
                printf("Case %d: %d\n",i,j);
                count=1;
                break;
            }
        }
        if(count==0){
            printf("Case %d: Not Found\n",i);
        }
    }
    return 0;
}