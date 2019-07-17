#include<iostream>
#include <string>
#include<vector>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseListRecursive (ListNode* head, ListNode* prevNode = NULL) {
	if (head == NULL)	return prevNode;
	ListNode* now = head;
	head = head->next;
	now->next = prevNode;
	return reverseListRecursive (head, now);
}

ListNode* reverseList(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}

	//iterative approach
	/*
	ListNode* c1 = NULL;
	ListNode* c2 = head;

	while (c2 != NULL) {
		ListNode* temp = c2->next;
		c2->next = c1;
		c1 = c2;
		c2 = temp;
	}

	return c1;
	*/

	//recursive approach
	return reverseListRecursive (head);
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
	ListNode* now = reverseList(head);
	current = now;
	while (current != NULL) {
		cout << current->val << ", ";
		current = current->next;
	}
	// cout << now->val << endl;
	return 0;
}