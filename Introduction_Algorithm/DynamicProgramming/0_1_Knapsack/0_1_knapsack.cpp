#include <bits/stdc++.h>
using namespace std;

int knapsack(int n,int s,int val[],int wei[]){
    if(n==0 || s==0) {
        return 0;
    }
    if(wei[n-1]<=s){
        int choice1=knapsack(n-1,s-wei[n-1],val,wei) + val[n-1];
        int choice2=knapsack(n-1,s,val,wei);
        return max(choice1,choice2);
    }
    else{
        return knapsack(n-1,s,val,wei);
    }
}

int main() {
    int n;
    cin>>n;
    int val[n],wei[n];
    for(int i =0;i<n;i++) cin>> val[i];
    for(int i =0;i<n;i++) cin >> wei[i];
    int s;
    cin>>s;
    cout << knapsack(n,s,val,wei);
}

/*
4
1 5 3 2
5 2 4 3
7

answer would be : 8

*/