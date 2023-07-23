/*
Problem Statement

You will be given two singly linked list of integer values as input. You need to check if all the elements of both list are same which means both list are same. If they are same print "YES" otherwise print "NO".

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the first singly linked list, and will terminate with -1.
Second line will contain the values of the second singly linked list, and will terminate with -1.
Constraints

1 <= N1, N2 <= 1000; Here N1 and N2 is the maximum number of nodes of the first and second linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" or "NO".
Sample Input 0

10 20 30 40 -1
10 20 30 40 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1
10 20 30 -1
Sample Output 1

NO
Sample Input 2

10 20 30 40 -1
40 30 20 10 -1
Sample Output 2

NO
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node (int value){
        this->value=value;
        next=NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int value) {
    if(head==NULL) {
        Node *newNode=new Node(value);
        head=newNode;
        tail=newNode;
    }
    else {
        Node *newNode=new Node(value);
        tail->next=newNode;
        tail=newNode;
    }
}

int main() {
    Node *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL;
    int value;
    while(true) {
        cin>>value;
        if(value==-1) break;
        insert_at_tail(head1, tail1, value);
    }
    while(true) {
        cin>>value;
        if(value==-1) break;
        insert_at_tail(head2, tail2, value);
    }
    Node *temp1=head1, *temp2=head2;
    while(temp1!=NULL && temp2!=NULL) {
        if(temp1->value!=temp2->value) {
            cout<<"NO";
            return 0;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1==NULL && temp2==NULL) cout<<"YES";
    else cout<<"NO";
    return 0;
}