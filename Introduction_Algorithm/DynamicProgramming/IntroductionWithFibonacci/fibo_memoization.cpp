#include <bits/stdc++.h>
using namespace std;
const int N=10e5+5;
int save[N];
int fib(int n){
    if(n==0 || n==1){
        return 1;
    }
    // memoization

    if(save[n]!=-1){
        return save[n];
    }
    int ans1=fib(n-1);
    int ans2=fib(n-2);
    save[n]=ans1+ans2;
    return ans1+ans2;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<=5;i++){
        save[i]=-1;
    }
    cout<<fib(n)<<endl;
    return 0;
 }