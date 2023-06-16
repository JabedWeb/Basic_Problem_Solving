#include <bits/stdc++.h>

using namespace std;

int main (){
    int num,deep,ball,ans=1;
    scanf("%d",&num);
    while(num--){
        ans=1;
        scanf("%d%d",&deep,&ball);
        for(int i=1;i<deep;i++){
            if(ball%2){
                ans=ans*2;
                ball=(ball+1)/2;
            }
            else{
                ans=ans*2+1;
                ball/=2;
            }
        }
        printf("%d\n",ans);
        
    }
    return 0;
}

// 5
// 4 2
// 3 4
// 10 1
// 2 2
// 8 128
// -1



// 12
// 7
// 512
// 3
// 255