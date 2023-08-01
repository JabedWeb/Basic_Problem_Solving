/*
Problem Statement

You will be given a binary tree as input in level order. You need to give the maximum and minimum values of all the leaf nodes available.

For example:

image

The output for the above tree will be: 60 40

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the maximum value then the minimum value of all leaf nodes.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60 40
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
void maxMinLeaf(Node * root){
    if(root == NULL) return;
    if(root->left == NULL &&  root->right == NULL){
        v.push_back(root->val);
    }
    maxMinLeaf(root->left);
    maxMinLeaf(root->right);
}
int main(){
    Node * root = input_tree();
    maxMinLeaf(root);
    int mx = INT_MIN;
    int mn = INT_MAX;
    for( auto val : v){
        mx = max(val,mx);
        mn = min(val,mn);
    }
    cout << mx << " " << mn << endl;
    return 0;
}