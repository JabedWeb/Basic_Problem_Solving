/*
Problem Statement

You will be given data for N students, where each student will have a name (nm), class (cls), section (s), student ID (id), math marks (math_marks), and English marks (eng_marks).

Your task is to sort the students data according to the total marks (sum of math_marks and eng_marks) in descending order. If multiple student have the same total marks then sort them according to the id in ascending order as the id will be unique.

Input Format

First line will contain N.
Next N lines will contain nm, cls, s, id, math_marks and eng_marks respectively.
Constraints

1 <= N <= 100
1 <= |nm| <= 100 and will contain only English alphabets.
1 <= cls <= 10
'A' <= s <= 'Z'
1 <= id <= 1000
0 <= math_marks, eng_marks <= 100
Output Format

Output the students data in descending order according to the total marks.
Sample Input 0

5
Munna 8 D 25 50 30
Shojoy 9 E 26 40 50
Asif 10 C 27 55 60
Joy 9 G 28 66 45
Bijoy 7 E 29 68 99
Sample Output 0

Bijoy 7 E 29 68 99
Asif 10 C 27 55 60
Joy 9 G 28 66 45
Shojoy 9 E 26 40 50
Munna 8 D 25 50 30
*/

#include <bits/stdc++.h>
using namespace std;

class Student{
    public : 
    string name;
    int cls;
    char section;
    int id;
    int math_marks;
    int eng_marks;
    int total_marks;

    void setTotalMarks(){
        total_marks = math_marks + eng_marks;
    }
};

int main() {
    int n;
    cin>>n;
    Student s[n];
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].cls>>s[i].section>>s[i].id>>s[i].math_marks>>s[i].eng_marks;
       s[i].setTotalMarks();
    }

    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            if(s[i].total_marks < s[j].total_marks){
                swap(s[i],s[j]);
            }
            else if(s[i].total_marks == s[j].total_marks){
                if(s[i].id > s[j].id){
                    swap(s[i],s[j]);
                }
            }

        }
    }


    for(int i =0;i<n;i++){
        cout<<s[i].name<<" "<<s[i].cls<<" "<<s[i].section<<" "<<s[i].id<<" "<<s[i].math_marks<<" "<<s[i].eng_marks<<endl;
    }
}