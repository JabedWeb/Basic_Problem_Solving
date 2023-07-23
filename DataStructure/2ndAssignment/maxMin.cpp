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

void insert_at_tail( Node* &head, Node* &tail, int value) {
    if(head==NULL){
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

// void print_node(Node *head) {
//     Node *temp=head;
//     while(temp!=NULL){
//         cout<<temp->value<<" ";
//         temp=temp->next;
//     }
// }

void print_node(Node *head) {
   Node *temp=head;
    int max=INT_MIN;
    int min=INT_MAX;
    while(temp!=NULL){
        if(temp->value>max){
            max=temp->value;
        }
        if(temp->value<min){
            min=temp->value;
        }
        temp=temp->next;
    }
    cout << max  <<" "<<  min <<endl;
}

int main() {
    Node *head=NULL;
    Node *tail=NULL;

    while(true){
        int x;
        cin>>x;
        if(x==-1){
            break;
        }
        insert_at_tail(head,tail,x);
    }
    print_node(head);
}