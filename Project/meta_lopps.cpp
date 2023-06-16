#include <bits/stdc++.h>
using namespace std;

void printabc(int n){
    if(n>0) cout << "a";
    if(n>1) cout << ",b";
    if(n>2) cout << ",c";
    if(n>3) cout << ",d";
    if(n>4) cout << ",e";
    if(n>5) cout << ",f";
    if(n>6) cout << ",g";
    if(n>7) cout << ",h";
}
void printblank(int n){
    for(int i=0;i<n;i++){
        cout << " ";
    }
}

void printarr(char ch[],int n){
    cout << "writeln(";
    for(int i=0;i<n;i++){
        if(i) cout <<","<< ch[i];
        else cout << ch[i];
    }
    cout <<")" <<endl;
   
}

void pascal_program (char ch[],char cur[],int n,int cnt){
    char *new_cur=new char[10];

    for(int i=0;i<n;i++){
        new_cur[i]=cur[i];
    }


    for(int i=0;i<cnt;i++){
         if(i==cnt-1){
            printblank(cnt-1);
            cout <<"else"<<endl;
            if(cnt<n){
                pascal_program(ch,new_cur,n,cnt+1);
            }
            if(cnt==n){
                printblank(cnt);
                printarr(new_cur,n);
            }
         }
         else {
            printblank(cnt-1);
            if(i) cout <<"else ";
            cout <<"if "<<cur[cnt-i-2] <<" < " <<ch[cnt-1]<<" then"<<endl;
            if(cnt<n){
                pascal_program(ch,new_cur,n,cnt+1);
            }
            if(cnt==n){
                printblank(cnt);
                printarr(new_cur,n);
            }
            swap(new_cur[cnt-i-2],new_cur[cnt-i-1]);
         }
    }
}


int main (){
    int testcase;
    bool ffff=false;
cin >> testcase;

        for(int i=0;i<testcase;i++){
           int n;
           cin >>n;
           if(ffff)cout <<endl;
              ffff=true;    
              cout << "program sort(input,output);" <<endl;
                cout << "var" <<endl;
                printabc(n);
                cout << ": integer;" <<endl;
                cout << "begin" <<endl;
                cout << "  readln(";
                printabc(n);
                cout << ");" <<endl;

                char ch[10];
                char cur[10];
                ch[0]='a',ch[1]='b',ch[2]='c',ch[3]='d',ch[4]='e',ch[5]='f',ch[6]='g',ch[7]='h';
                cur[0]='a',cur[1]='b',cur[2]='c',cur[3]='d',cur[4]='e',cur[5]='f',cur[6]='g',cur[7]='h';
                if(n>1)
                pascal_program(ch,cur,n,2);
                else {
                    cout << "  writeln(a);" <<endl;
                }
                cout << "end." <<endl;
        }
}