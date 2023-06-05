#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct HuffmanNode {
    int item;
    char c;
    HuffmanNode* left;
    HuffmanNode* right;
};

struct ImplementComparator {
    bool operator()(HuffmanNode* x, HuffmanNode* y) {
        return x->item > y->item;
    }
};


void printCode(HuffmanNode* root, string s) {
    if (root->left == nullptr && root->right == nullptr && isalpha(root->c)) {
        cout << root->c << " | " << s << endl;
        return;
    }
    printCode(root->left, s + "0");
    printCode(root->right, s + "1");
}


int main() {
    int n = 5;
    char charArray[] = {'A', 'B', 'C', 'D', 'R'};
    int charfreq[] = {5, 2, 1, 1, 2};

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, ImplementComparator> q;

    for (int i = 0; i < n; i++) {
        HuffmanNode* hn = new HuffmanNode();
        hn->c = charArray[i];
        hn->item = charfreq[i];
        hn->left = nullptr;
        hn->right = nullptr;
        q.push(hn);
    }

    HuffmanNode* root = nullptr;

    while (q.size() > 1) {
        HuffmanNode* x = q.top();
        q.pop();

        HuffmanNode* y = q.top();
        q.pop();

        HuffmanNode* f = new HuffmanNode();
        f->item = x->item + y->item;
        f->c = '-';
        f->left = x;
        f->right = y;

        root = f;

        q.push(f);
    }

    cout << " Char | Code " << endl;
    cout << "-------" << endl;
    printCode(root, "");

    return 0;
}
