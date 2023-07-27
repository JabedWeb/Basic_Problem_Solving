/*
Problem
Submissions
Leaderboard
Discussions
Problem Statement

There are a list of N values which were inserted into a stack and a list of M values which were inserted into a queue. After that the elements of the stack and queue are removed and put them into the list where the belong. You need to tell if both of the list are same or not after removing those elements from the stack and queue.

Note: You need to implement Stack and Queue to solve this problem. You can't insert those values to anything else and also you can't use STL here. You can implement stack and queue by linked list or array as you wish.

Input Format

First line will contain N and M.
Second line will contain list A with N values.
Third line will contain list B with M values.
Constraints

1 <= N, M <= 10^6
0 <= Values of list A and B <= 1000
Output Format

Output "YES" if they were same, otherwise "NO".
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
10 20 30 40 50
50 40 30 20
Sample Output 2

NO

*/


#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack{
    public:
    int sz=0;
    Node* head=NULL;
    Node* tail=NULL;
    void push(int val){ 
        sz++;
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail=tail->next;
        }
    }
    void pop(){
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;
        if(tail==NULL){
            head=NULL;
        }
        else{
            tail->next = NULL;
        }
        delete deleteNode;
    } 
    int top(){
        return tail->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0) return true;
        else return false;
    }
  
};

class myqueue{
    public:
    int sz=0;
    Node* head=NULL;
    Node* tail=NULL;
    void push(int val){ 
        sz++;
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail=tail->next;
        }
    }
    void pop(){
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if(head==NULL){
            tail=NULL;
        }
        else{
            head->prev = NULL;
        }
        delete deleteNode;
    } 
    int front(){
        return head->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0) return true;
        else return false;
    }
  
};

int main() {
    int n,m;
    cin>>n>>m;
    myStack s;
    myqueue q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    bool flag = true;
    if(s.size()!=q.size()){
        cout<<"NO"<<endl;
        return 0;
    }
    while(!s.empty() && !q.empty()){

        if(s.top()!=q.front()){
            flag = false;
            break;
        }
        s.pop();
        q.pop();
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
    
}