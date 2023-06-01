#include <bits/stdc++.h>
using namespace std;


string uppercase(string checkString) {
    string s=checkString;
    for(unsigned long long int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
    }
    return s;
}

int main() {
    string s;
    getline(cin, s);

    // convert string to uppercase
   string sentence= uppercase(s);
   // cout << sentence << endl;

    string name=uppercase("raTul");
   // cout << name << endl;

    unsigned long long int findPosition = sentence.find(name);

    //cout << findPosition << endl;

    //check name is in the sentence or not
    if(findPosition < sentence.length()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    
   return 0;
}