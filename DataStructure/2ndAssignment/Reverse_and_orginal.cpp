/**
Problem Statement

You need to take a singly linked list of integer value as input. Then you need to print the singly linked list in reverse order, after that print the original linked list also.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 10^9; Here V is the value of each node.
Output Format

In first line, output the linked list in reverse order.
In second line, print the original linked list.
Sample Input 0

10 20 30 40 50 -1
Sample Output 0

50 40 30 20 10 
10 20 30 40 50 
Sample Input 1

20 40 50 10 -1
Sample Output 1

10 50 40 20 
20 40 50 10
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
void print_linked_list(Node* head) {
    Node *temp=head;
    while(temp!=NULL) {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void print_recursive(Node* head) {
    if(head==NULL) return;
    print_recursive(head->next);
    cout<<head->value<<" ";
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
    print_recursive(head);
    cout<<endl;
    print_linked_list(head);
}