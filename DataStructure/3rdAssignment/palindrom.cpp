/*

Problem Statement

You need to take a singly linked list of integer value as input. You need to tell if the singly linked list forms a palindrome or not.

Note: You need to solve this using singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" if it forms a palindrom otherwise print "NO".
Sample Input 0

1 2 3 2 1 -1
Sample Output 0

YES
Sample Input 1

1 2 2 1 -1
Sample Output 1

YES
Sample Input 2

1 -1
Sample Output 2

YES
Sample Input 3

1 2 3 1 -1
Sample Output 3

NO


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

void reverse(Node* &head,Node * cur){
    if(cur->next==NULL) {
        head=cur;
        return;
    }
    reverse(head, cur->next);
    Node *q=cur->next;
    q->next=cur;
    cur->next=NULL;
}
void copy_node(Node* head, Node* tail) {
    Node* newHead=NULL;
    Node* newTail=NULL;
    Node* temp=head;
    while(temp!=NULL) {
        insert_at_tail(newHead, newTail, temp->value);
        temp=temp->next;
    }
    reverse(newHead, newHead);

    //check palindrome
    Node* temp1=head;
    Node* temp2=newHead;
    bool flag=true;
    while(temp1!=NULL && temp2!=NULL) {
        if(temp1->value!=temp2->value) {
            flag=false;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(flag) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
}

int main() {
    Node* head=NULL;
    Node* tail=NULL;
    while(true){
        int value;
        cin>>value;
        if(value==-1) break;
        insert_at_tail(head, tail, value);
    }
    copy_node(head, tail);
}