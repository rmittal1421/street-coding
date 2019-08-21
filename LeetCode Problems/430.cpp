/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* rec_flat_DLL (Node* &head, Node* prev = NULL) {
        if (head == NULL) return prev;
        else if (head->child != NULL) {
            Node* last = rec_flat_DLL (head->child);
            if (head->next!=NULL) head->next->prev = last;
            last->next = head->next;
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;
        }
        return rec_flat_DLL (head->next, head);
    }
    
    Node* flatten(Node* head) {
        Node* last = rec_flat_DLL (head);
        return head;
    }
};
