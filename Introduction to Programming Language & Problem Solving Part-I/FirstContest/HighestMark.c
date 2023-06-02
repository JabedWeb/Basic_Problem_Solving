/*
There are N students in a class. Recently they got their Math course marks. One of them got the highest marks. So now they want to know how much more marks they need to get the highest mark. Can you calculate for every student what is the difference between their marks and the highest marks and print them!

Input Format

First line will contain N
Second line will contain the marks of N students
Constraints

1 <= N <= 100
0 <= Marks <= 100
Output Format

Output the difference between the marks of any student and highest marks
Sample Input 0

5
15 25 50 24 48
Sample Output 0

35 25 0 26 2



*/


#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int n;
    printf("Please enter the number\n");
    scanf("%d",&n);
    int array[n];
    int higMark =-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&array[i]);
        if(array[i]>higMark){
            higMark=array[i];
        }
    }
    printf("%d\n",higMark);
    for(int i=1;i<=n;i++){
        int difference=higMark-array[i];
        printf("%d ",difference);
    }
    return 0;
}