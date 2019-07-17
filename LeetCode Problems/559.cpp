#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

typedef Node* nd;
typedef vector<Node*> vn;

class Solution {
public:
    int maxDepth(Node* root) {
        int count = 0;
        if (!root) return count;
    }
};

int main() {
    vector<int> v1 = NULL;
    if(v1) cout<<"it exists"<<endl;
    else cout<<"It does not exist"<<endl;
    // nd child3 = new Node(4, NULL);
    // vn c2 = {child3};

    // nd child1 = new Node(2, c2);
    // nd child2 = new Node(3, NULL);
    
    // vn c1 = {child1, child2};
    
    // // Solution sln;
    // // Node* root = new Node(1, vector<Node*> );
    // Node* root = new Node(1, c1);
    // cout << root->val << endl;
    return 0;
}