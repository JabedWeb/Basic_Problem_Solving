/*
Problem Statement

You will be given two strings S and X. You need to replace all X from string S with a '$' sign.

Input Format

First line will contain T, the number of test cases.
Next T lines will contain a line with S and X.
Constraints

1 <= T <= 1000
1 <= |S|, |X| <= 1000
|X| <= |S|
Output Format

For each test cases output the modified string S.
Sample Input 0

2
thatsagoodmomentforgoodrelations good
canyoutellmewhereicanfindheriwillbegreatefultoyouifyoutellmetheanswer you
Sample Output 0

thatsa$momentfor$relations
can$tellmewhereicanfindheriwillbegreatefulto$if$tellmetheanswer


*/




#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin>>n;
    string s,x;
    for(int i=0;i<n;i++){
    // getline(cin,s);
    // getline(cin,x);
    cin>>s>>x;
    unsigned long long int findPosition = s.find(x);
    while (findPosition < s.length()) {
        // cout << findPosition << endl;
        s.replace(findPosition, x.length(), "$");
        // to avoid every time find the string from the beginning
        //findPosition = s.find(x, findPosition + x.length());
        findPosition = s.find(x, findPosition + 1);
    }

    // after modified string
    cout << s<<endl;
    }

    return 0;
}