/*
Problem Statement

You will be given a binary tree as input in level order. Also you will be given a level X. You need to print all the node's values in that level from left to right. Assume that level starts from 0.

For example:

image

If X=2, then the output for the above tree will be: 40 50 60

Note: If the level X is not a valid level, the print "Invalid".

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
0 <= X <= 10^5
Output Format

Output all the node's values in level X.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
0
Sample Output 0

10
Sample Input 1

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
1
Sample Output 1

20 30
Sample Input 2

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
2
Sample Output 2

40 50 60
Sample Input 3

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
3
Sample Output 3

Invalid
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
bool level_nodes(Node * root,int lnumber){
    queue<pair<Node * ,int>> q;
    q.push({root,0});
    bool foundLevel = false;
    while(!q.empty()){
        pair<Node * ,int> f = q.front();
        q.pop();
        Node * n = f.first;
        int l = f.second;

        if(lnumber == l ){
            v.push_back(n->val);
            foundLevel = true;
        }
        if(n->left) q.push({n->left,l+1});
        if(n->right) q.push({n->right,l+1});
       
    }
    return foundLevel;

}
int main(){
    Node * root = input_tree();
    int lnumber;
    cin >> lnumber;

    if(!level_nodes(root,lnumber)){
        cout << "Invalid" << endl;
    }else {
            for(auto val : v){
            cout << val << " ";
        }
    }
    

    return 0;
}