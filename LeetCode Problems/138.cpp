/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* generateNewNode (int val) {
        Node* temp = new Node (val, NULL, NULL);
        return temp;
    }
    
    Node* copyRandomList(Node* head) {
        Node* copyHead = NULL;
        if (!head) return copyHead;
        
        unordered_map<Node*, Node*> umap; 
        
        Node* current = head;
        Node* now = copyHead;
        Node* randomNode = NULL;
        Node* newNode = NULL;
        while (current) {
            if (umap.find (current) != umap.end()) {
                newNode = umap.find(current)->second;
            } else {
                newNode = generateNewNode (current->val);
                umap[current] = newNode;
            }
            
            if (!copyHead) {
                copyHead = newNode;
                now = copyHead;
            }
            else {
                now->next = newNode;
                now = now->next;
            }
            
            Node* oldRandom = current->random;
            if (umap.find(oldRandom) != umap.end()) {
                now->random = umap.find (oldRandom)->second;
            } else {
                if (!oldRandom) now->random = NULL;
                else now->random = generateNewNode (oldRandom->val);
                umap[oldRandom] = now->random;
            }
            current = current->next;
        }
        
        return copyHead;
    }
};
