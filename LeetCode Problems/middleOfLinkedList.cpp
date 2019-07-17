#include<iostream>
#include <string>
#include<vector>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
    std::vector<ListNode*> vec;
    ListNode* current = head;
    while (current != NULL) {
    	vec.push_back (current);
    	current = current->next;
    }
    return vec[vec.size()/2];
} 

ListNode* generateNewNode (int value) {
	ListNode* newNode = new ListNode (value);
	return newNode;
}

int main () {
	ListNode* head = generateNewNode (0);
	ListNode* current = head;
	for (int i = 0; i < 3; i++) {
		current->next = generateNewNode (i+1);
		current = current->next;
	}
	ListNode* now = middleNode(NULL);
	// cout << now->val << endl;
	return 0;
}




