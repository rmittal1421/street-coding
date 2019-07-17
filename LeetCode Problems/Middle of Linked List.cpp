#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    std::vector<ListNode*> vec;
    ListNode* current = head;
    while (current != NULL) {
    	vec.push (current);
    	current->next = head->next;
    }
    int size = vec.size();
    if (size%2==0) {return vec.get (size/2);}
    else {return vec.get ((size/2) + 1);}
} 

void addFirstNode (ListNode* head, int value) {
	if (head == NULL) {
		head = new ListNode(value);
	}
}

void addNode (ListNode* head, int value) {
	ListNode* node = new ListNode(value);
	node->next = head;
	head = node;
} 

int main () {
	ListNode* head = NULL;
	addFirstNode (head, 0);
	for (int i = 0; i < 4; i++) {
		addNode (i+1, head);
	}
	cout << middleNode(head)->value << endl;
}




