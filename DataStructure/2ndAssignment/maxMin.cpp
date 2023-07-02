/*
Problem Statement

You need to take a singly linked list of integer value as input and print the maximum and minimum value of the singly linked list.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the maximum value then the minimum value.
Sample Input 0

2 4 1 5 3 6 -1
Sample Output 0

6 1
Sample Input 1

2 -1
Sample Output 1

2 2
*/



#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node(int value) {
        this->value=value;
        next=NULL;
    }
};

void insert_at_tail()

int main() {
    Node *head=NULL;
    cout <<"Option 1 : Insert at tail"<<endl;
    int op;
    cin >>op;
    if(op==1){

    }
}