/*
Problem Statement

You need to take a singly linked list of integer value as input. You need to remove the duplicate values and print the unique values in ascending order.

Note: You need to solve this using singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^3; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the new singly linked list in ascending order.
Sample Input 0

1 2 1 3 2 4 2 1 3 -1
Sample Output 0

1 2 3 4
Sample Input 1

2 2 2 2 -1
Sample Output 1

2
Sample Input 2

10 4 2 1 5 6 -1
Sample Output 2

1 2 4 5 6 10 
Sample Input 3

5 4 3 5 4 2 5 3 2 4 5 1 2 3 4 5 -1
Sample Output 3

1 2 3 4 5
Sample Input 4

4 3 5 4 2 3 2 4 1 2 3 4 -1
Sample Output 4

1 2 3 4 5
Submissions: 589
Max Score: 20
Difficulty: Easy
Rate This Challenge:
More

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

void sort (Node *head) {
    for(Node *i=head; i!=NULL; i=i->next) {
        for(Node *j=i->next; j!=NULL; j=j->next) {
            if(i->value > j->value) {
                swap(i->value, j->value);
            }
        }
    }
}

void print_linked_list(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        return;
    }

    // Print the first element
    cout << temp->value << " ";
    
    // Traverse the list and print elements while skipping duplicates
    while (temp->next != NULL) {
        if (temp->value != temp->next->value) {
            cout << temp->next->value << " ";
        }
        temp = temp->next;
    }
}


int main() {
    Node *head=NULL, *tail=NULL;

    while(true){
        int value;
        cin>>value;
        if(value==-1) break;
        insert_at_tail(head, tail, value);
    }
    sort(head);
    print_linked_list(head);
}