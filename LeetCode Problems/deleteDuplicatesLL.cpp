#include<iostream>
#include <string>
#include<vector>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode* now = head;
	ListNode* nxt = head->next;
	int val = now->val;

	while (nxt != NULL) {
		val = now->val;
		if (val == nxt->val) {
			nxt = nxt->next;
		} else {
			now->next = nxt;
			now = nxt;
			nxt = nxt->next;
		}
	}
	now->next = NULL;
	return head;
}

ListNode* generateNewNode (int value) {
	ListNode* newNode = new ListNode (value);
	return newNode;
}

int main () {
	ListNode* head = generateNewNode (0);
	ListNode* current = head;
	for (int i = 0; i < 3; i++) {
		int j = 0;
		while (j <= i) {
			current->next = generateNewNode (i+1);
			current = current->next;
			current->next = generateNewNode (i+1);
			current = current->next;
			j++;
		}
	}
	ListNode* thisOne = head;
	cout << "Before" << endl;
	while (thisOne != NULL) {
		cout << thisOne->val << endl;
		thisOne = thisOne->next;
	}
	ListNode* now = deleteDuplicates(head);
	cout << "After" << endl;
	while (now != NULL) {
		cout << now->val << endl;
		now = now->next;
	}
	return 0;
}




