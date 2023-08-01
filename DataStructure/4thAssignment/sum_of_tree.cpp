/*
Problem Statement

You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree.

For example:

image

The output for the above tree will be: 210

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the total sum of that tree.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

210

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
int sum = 0;
int sumTotal(Node *root){
    queue <Node*>q;
    if(root) q.push(root);
    while(!q.empty()){
        Node *p = q.front();
        q.pop();
        sum = sum + p->val;
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return sum;
}
int main(){
    Node * root = input_tree();
    int sum_total = sumTotal(root);
    cout << sum_total << endl;
    return 0;
}