/*

Problem Statement

You will be given data for N students, where each student will have a name (nm), class (cls), section (s) and student ID (id) which will be unique.

Your task is reverse their id and print all the students data. That means the id of the first student will be replaced by the id of the last student, the id of the second student will be replaced by the id of the second last student and so on. See the sample input and output for more clarifications.

Input Format

First line will contain N.
Next N lines will contain nm, cls, s, and id respectively.
Constraints

1 <= N <= 100
1 <= |nm| <= 100 and will contain only English alphabets.
1 <= cls <= 10
'A' <= s <= 'Z'
1 <= id <= 100
Output Format

Output all the students data after reversing their id.
Sample Input 0

3
Rakib 7 B 90
Sakib 10 A 85
Ahsan 9 C 36
Sample Output 0

Rakib 7 B 36
Sakib 10 A 85
Ahsan 9 C 90
*/

#include <bits/stdc++.h>
using namespace std;

class Student{
    public : 
    string name;
    int cls;
    char section;
    int id;
};

int main() {
    int n;
    cin>>n;

    Student s[n];
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].cls>>s[i].section>>s[i].id;
    }
    // reverse the unique id
    for(int i=0;i<n/2;i++){
        // int temp=s[i].id;
        // s[i].id=s[n-i-1].id;
        // s[n-i-1].id=temp;
        swap(s[i].id,s[n-i-1].id);
    }

    for(int i=0;i<n;i++){
        cout<<s[i].name<<" "<<s[i].cls<<" "<<s[i].section<<" "<<s[i].id<<endl;
    }
}