/*
Problem Statement

Write a program to determine if a given string contains the word "Ratul." If the word is present in the string, the program should output "YES," otherwise it should output "NO."

NOTE: You need to find only "Ratul"; not "ratul" or "RatuL" or any other form. Words are separated by spaces.

Input Format

Input will contain a string S containing names. There is a space in between two names.
Constraints

1 <= |S| <= 1000; Here |S| means the length of the string.
Output Format

Output YES or NO according to the question.
Sample Input 0

Rahat Rifat Sakib Asif Sifat Ratul Munna
Sample Output 0

YES
Sample Input 1

Rahat Rifat Sakib Asif Sifat Munna
Sample Output 1

NO


*/


#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    getline(cin, s);

    string name = "Ratul";


    string Sentence =s;
    string Name = name;

    
    stringstream ss(Sentence);
    string word;
    bool isRatulAvailable = false;


    while (ss >> word) {
        if (word == Name) {
            isRatulAvailable = true;
            break;
        }
    }

    if (isRatulAvailable) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
