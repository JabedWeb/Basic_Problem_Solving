/*
Problem Statement

You are given a doubly linked list of strings. These strings refer to web addresses without any spaces. You will be given Q queries. In each query you will be given some commands. Type of commands are -

visit address - You need to go to that address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
next - You need to go to the next address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
prev - You need to go to the previous address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
Note: You can use Linked List or STL List to solve this problem.

Input Format

First line will contain the values of the doubly linked list, and will terminate with the string "end".
Second line will contain Q.
Next Q lines will contain the commands. It is guranteed that you will get "visit address" command at first which will contain a valid address. It will not contain valid address everytime!
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
1 <= Q <= 1000;
1 <= |Address| <= 100; Here |Address| is the length of the string address.
Output Format

For each query output as asked.
Sample Input 0

facebook google phitron youtube twitter end
12
visit phitron
prev
prev
prev
prev
next
visit twitter
next
next
prev
visit django
prev
Sample Output 0

phitron
google
facebook
Not Available
Not Available
google
twitter
Not Available
Not Available
youtube
Not Available
phitron

*/
#include <iostream>
using namespace std;

class Node {
public:
    string val;
    Node* prev;
    Node* next;

    Node(string val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string val) {
    if (head == NULL) {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void visit(Node* &current, Node* head, string val) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == val) {
            cout << val << endl;
            current = temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Available" << endl;
}

void next(Node* &current) {
    if (current == NULL || current->next == NULL) {
        cout << "Not Available" << endl;
        return;
    }
    current = current->next;
    cout << current->val << endl;
}

void prev(Node* &current) {
    if (current == NULL || current->prev == NULL) {
        cout << "Not Available" << endl;
        return;
    }
    current = current->prev;
    cout << current->val << endl;
}

int main() {
    string val;
    Node* head = NULL;
    Node* tail = NULL;

    while (cin >> val && val != "end") {
        insert_at_tail(head, tail, val);
    }

    int Q;
    cin >> Q;
    string command, address;
    cin >> command >> address;

    Node* current = NULL;
    // First visit
    visit(current, head, address);

    while (--Q) {
        cin >> command;
        if (command == "visit") {
            cin >> address;
            visit(current, head, address);
        } else if (command == "next") {
            next(current);
        } else if (command == "prev") {
            prev(current);
        }
    }

    return 0;
}
