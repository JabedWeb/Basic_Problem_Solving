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

    for (int i = 1; i <= pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
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
        } else if (X > size(head)) {
            cout << "Invalid" << endl;
            break;
        } else {
            insert_any_pos(head, tail, X, V);
        }

        if (head != NULL) {
            print_list_forward(head);
            print_list_backward(tail);
        }
    }

    return 0;
}