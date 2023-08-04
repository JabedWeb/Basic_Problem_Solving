/**
 Question: You are given an array of N positive integers. The next line will contain an integer K. You need to tell whether there exists more than one occurrence of K in that array or not. If there exists more than one occurrence of K print YES, Otherwise print NO.
See the sample input-output for more clarification.
The given array will be sorted in increasing order. And it is guaranteed that at least one occurrence of K will exist.	 You must solve this in O(logn) complexity.

7
1 3 4 6 6 9 17		
6

YES

10
0 1 2 3 4 5 6 7 8 9
3

NO



*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr[N];
void binary_search(int l,int r,int k,int count){
    if(l>r){
        cout<<"NO"<<endl;
        return;
    }
    int mid = (l + r) / 2;
    if(arr[mid]==k){
        count++;
        if(count==2){
            cout<<"YES"<<endl;
            return;
        }
    }
    if(k<arr[mid]){
        binary_search(l,mid-1,k,count);
    }
    else{
        binary_search(mid+1,r,k,count);
    }
}

int main() {
    int n,k;
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];
    //for(int i =0;i<n;i++) cout<<arr[i]<< " ";
    cin>>k;

    int count = 0;

    binary_search(0,n-1,k, count);
}