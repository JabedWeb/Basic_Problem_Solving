/*
Problem Statement

You need to take a singly linked list of integer value as input. Then you need to sort the linked list in descending order and print the middle element of it. If there are multiple values in the middle, print both.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the value/values of the middle element.
Sample Input 0

20 10 40 30 50 -1
Sample Output 0

30
Sample Input 1

20 30 10 40 60 50 -1
Sample Output 1

40 30
Sample Input 2

726 -1
Sample Output 2

726
Sample Input 3

348 726 -1
Sample Output 3

726 348
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

void sort(Node* &head) {
    for(Node *i=head; i!=NULL; i=i->next) {
        for(Node *j=i->next; j!=NULL; j=j->next) {
            if(i->value<j->value) {
                swap(i->value, j->value);
            }
        }
    }
}
void print_linked_list(Node* head,int count) {
    //if mid is single
    //then print mid
    // if mid is double
    // then print both
    if(count%2==0) {
        int mid=count/2;
        int i=1;
        for(Node *temp=head; temp!=NULL; temp=temp->next) {
            if(i==mid) {
                cout<<temp->value<<" ";
            }
            if(i==mid+1) {
                cout<<temp->value<<" ";
            }
            i=i+1;
        }
    }
    else {
        int mid=count/2;
        int i=1;
        for(Node *temp=head; temp!=NULL; temp=temp->next) {
            if(i==mid+1) {
                cout<<temp->value<<" ";
            }
            i=i+1;
        }
    }

}
int main() {
    Node *head=NULL, *tail=NULL;
    int value;
    int count=0;
    while(true) {
        cin>>value;
        if(value==-1) {
            break;
        }
        count=count+1;
        insert_at_tail(head, tail, value);

    }
    sort(head);
    print_linked_list(head,count);
    return 0;

}