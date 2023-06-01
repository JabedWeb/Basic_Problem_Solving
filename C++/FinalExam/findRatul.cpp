
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


    unsigned long long int findPosition = sentence.length()+1;
    // if we get the name in the sentence first then we don't give any space before the name
    if(sentence.find(name) == 0) {
        findPosition = sentence.find(name+" ");
    }
        // if we get the name in the sentence last then we give a space before the name
    else if(sentence.find(name) == sentence.length()-name.length()) {
        findPosition = sentence.find(" "+name);
    }
            // if we get the name in the sentence middle then we give a space before and after the name
        else {
       findPosition = sentence.find(" "+name+" ");
    }


    //cout << findPosition << endl;

    //check name is in the sentence or not
    if(findPosition < sentence.length()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    
   return 0;
}