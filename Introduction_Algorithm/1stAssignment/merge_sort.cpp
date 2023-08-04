/*
Question: Write a C++ program that takes N integer numbers and sorts them in non-increasing order using Merge Sort. 
You can’t use any built-in function for sorting.
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];




void merge_conquer(int l,int r,int mid){
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int left[left_size+1];
    int right[right_size+1];

    for(int i=l,j=0;i<=mid;i++,j++){
        left[j] = arr[i];
    }

    for(int i=mid+1,j=0;i<=r;i++,j++){
        right[j] = arr[i];
    }

    left[left_size] = INT_MIN;
    right[right_size] = INT_MIN;

    int lp = 0;
    int rp = 0;
    for(int i=l;i<=r;i++){
        if(left[lp]>=right[rp]){
            arr[i] = left[lp];
            lp++;
        }
        else{
            arr[i] = right[rp];
            rp++;
        }
    }
}

void merge_sort(int l,int r){

    if(l==r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge_conquer(l,r,mid);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    merge_sort(0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}