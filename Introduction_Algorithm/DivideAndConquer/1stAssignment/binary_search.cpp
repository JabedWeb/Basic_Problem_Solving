/*
Question: Write a C++ program that takes N integer numbers that are sorted and distinct. The next line will contain an integer k. You need to tell whether K exists in that array or not. If it exists, print its index otherwise print “Not Found”. 	
You must solve this in O(logn) complexity.
8
-4 0 2 6 9 10 29 54
29

6


10
0 1 2 3 4 5 6 7 8 9
-3

Not Found



*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];

void binary_search(int l,int r,int k){
    if(l>r){
        cout<<"Not Found"<<endl;
        return;
    }

    int mid = (l + r) / 2;
    if(arr[mid]==k){
        cout<<mid<<endl;
        return;
    }
    if(k<arr[mid]){
        binary_search(l,mid-1,k);
    }
    else{
        binary_search(mid+1,r,k);
    }

}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    binary_search(0,n-1,k);
    return 0;
}