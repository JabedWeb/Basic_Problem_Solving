/*

Question: You are given two sorted arrays arr1 and arr2 in descending order. Your task is to merge these two arrays into a new array result using the merge sort technique, but Instead of merging the arrays in ascending order, you need to merge them in descending order to create the result array.
	 
You cannot use stl sort function here
4
8 6 4 2	
4
7 5 3 1

8 7 6 5 4 3 2 1


*/

#include <bits/stdc++.h>
using namespace std;

const int n=1e5+7;
int arr1[n],arr2[n],result[n];

void merge(int* arr1,int size1,int* arr2,int size2,int* result){

    arr1[size1] = INT_MIN;
    arr2[size2] = INT_MIN;

    int lp = 0;
    int rp = 0;

    for(int i=0;i<size1+size2; i++){
        if(arr1[lp]>=arr2[rp]){
            result[i] = arr1[lp];
            lp++;
        }
        else{
            result[i] = arr2[rp];
            rp++;
        }
    }
}

int main() {
    int firstSize,secondSize;
    cin>>firstSize;
    for(int i=0;i<firstSize;i++) cin>>arr1[i];
    cin>>secondSize;
    for(int i=0;i<secondSize;i++) cin>>arr2[i];

    merge(arr1,firstSize,arr2,secondSize,result);

    for(int i=0;i<firstSize+secondSize;i++) cout<<result[i]<<" ";


}