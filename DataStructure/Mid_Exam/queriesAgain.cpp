/*
Problem Statement

You have a doubly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

You need to insert the value V at index X. Assume that index starts from 0.
After that for each query you need to print the linked list from left to right and right to left.
If the index is invalid, then print "Invalid".
Note: You must use doubly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 1000;
0 <= V <= 1000
Output Format

For each query print the linked list from left to right and right to left or print "Invalid" as asked.
Print "L -> " before printing the linked list from left to right.
Print "R -> " before printing the linked list from right to left.
Sample Input 0

5
1 10
0 10
1 20
3 30
2 30
Sample Output 0

Invalid
L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
Invalid
L -> 10 20 30 
R -> 30 20 10 

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

int size(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void head_insertion(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void tail_insertion(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

void print_list_forward(Node* head) {
    Node* temp = head;
    cout << "L -> ";
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_list_backward(Node* tail) {
    Node* temp = tail;
    cout << "R -> ";
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insert_any_pos(Node*& head, Node*& tail, int pos, int val) {
    if (pos < 0 || pos > size(head)) {
        cout << "Invalid" << endl;
        return;
    }

    if (pos == 0) {
        head_insertion(head, tail, val);
        return;
    }

    if (pos == size(head)) {
        tail_insertion(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            head_insertion(head, tail, V);
        } else if (X == size(head)) {
            tail_insertion(head, tail, V);
        } else {
            insert_any_pos(head, tail, X, V);
        }

        if (X<size(head)) {
            print_list_forward(head);
            print_list_backward(tail);
        }
    }

    return 0;
}
