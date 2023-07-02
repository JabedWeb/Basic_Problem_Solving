#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int mid=(n+1)/2;
            if(i==mid){
                if(i==j){
                 cout<<"X";
                }
                else{
                    cout<<" ";
                }
            }
            else if (i==j){
                cout <<"\\";
            }
            else if (i+j==n+1){
                cout<<"/";
            }
            else cout<<" ";

            // if(j==i || j==n-i+1) cout<<"*";
            // else cout<<" ";  
        }
        cout<<endl;
    }
    return 0;
}