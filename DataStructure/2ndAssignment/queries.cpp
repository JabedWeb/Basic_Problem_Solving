/*
Problem Statement

You have a singly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
And if X is 1 then you will insert the value V to the tail of the linked list.
After that for each query you need to print the value of the head and tail of the list.
Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 10^6;
0 <= X <= 1;
0 <= V <= 10^9
Output Format

For each query ouput the value of head and tail of the linked list.
Sample Input 0

5
0 10
0 20
1 30
0 40
1 50
Sample Output 0

10 10
20 10
20 30
40 30
40 50

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

void insert_at_head(Node* &head,Node* &tail ,int value) {
    if(head==NULL) {
        Node *newNode=new Node(value);
        head=newNode;
        tail=newNode;
    }
    else {
        Node *newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
}

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
    int Q;
    cin>>Q;
    Node *head=NULL;
    Node *tail=NULL;
    while(Q--) {
        int X,V;
        cin>>X>>V;
        if(X==0){
            insert_at_head(head,tail,V);
        }
        else {
            insert_at_tail(head,tail,V);
        }
        cout<<head->value<<" "<<tail->value<<endl;
    }
    return 0;
}