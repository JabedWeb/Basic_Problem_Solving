/*
Problem Statement

You will be given a binary tree as input in level order. You need to print the binary tree in reverse way. Here, reverse way means you need to print from the last level and from left to right.

For example:

image

The output for the above tree will be: 40 50 60 20 30 10

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the tree in reverse way as described.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

40 50 60 20 30 10


*/


#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int  val;
    Node * left;
    Node * right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* input_tree(){
    int val;
    cin >> val;
    Node * root;
    if( val == -1) root = NULL;
    else root = new Node(val);
    queue<Node*> q;
    if( root) q.push(root);
    while(!q.empty()){
        //1st task
        Node * p = q.front();
        q.pop();

        // 2nd task
        int l, r;
        cin >> l >> r;
        Node *  left;
        Node * right;
        if( l == -1) left = NULL;
        else left = new Node(l);
        if( r == -1) right = NULL;
        else right = new Node(r);

        p->left = left;
        p->right = right;

        // 3rd task
        if( p->left){
            q.push(p->left);
        }
        if( p->right) q.push(p->right);

    }
    return root;
}
vector<int> v;
void level_order(Node * root){
    if(root == NULL) return;
     queue <Node*> q;
     q.push(root);
     while(!q.empty()) {
        Node* f = q.front();
        q.pop();

        v.push_back(f->val);
        if(f->right) q.push(f->right);
        if(f->left) q.push(f->left);
        
     }
}
int main(){
    Node * root = input_tree();
    level_order(root);
    reverse(v.begin(), v.end());
    for(int val : v){
        cout << val << " ";
    }
    return 0;
}