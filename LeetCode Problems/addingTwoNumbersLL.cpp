#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generateNewNode (int value) {
	ListNode* newNode = new ListNode (value);
	return newNode;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<int> s1, s2;
	ListNode* curr = l1;
	while (curr != NULL) {
		s1.push(curr->val);
		curr = curr->next;
	}
	curr = l2;
	while (curr != NULL) {
		s2.push(curr->val);
		curr = curr->next;
	}

	int ans = 0;
	int carryOver = 0;
	while (!s1.empty() && !s2.empty()) {
		int a = s1.top();
		int b = s2.top();
		s1.pop();
		s2.pop();
		ListNode* newNode = generateNewNode ((a + b + carryOver)%10);
		carryOver = (a + b + carryOver)/10;
		newNode->next = curr;
		curr = newNode;
	}
	if (!s1.empty()) {
		while (!s1.empty()) {
			ListNode* newNode = generateNewNode ((s1.top() + carryOver)%10);
			carryOver = (s1.top() + carryOver)/10;
			s1.pop();
			newNode->next = curr;
			curr = newNode;
		}
	} else if (!s2.empty()) {
		while (!s2.empty()) {
			ListNode* newNode = generateNewNode ((s2.top() + carryOver)%10);
			carryOver = (s2.top() + carryOver)/10;
			s2.pop();
			newNode->next = curr;
			curr = newNode;
		}
	}
	if (carryOver != 0) {
		ListNode* newNode = generateNewNode (carryOver);
		newNode->next = curr;
		curr = newNode;
	}
	return curr;
}

int main () {
	ListNode* head = generateNewNode (5);
	// head->next = generateNewNode (2);
	// head->next->next = generateNewNode (4);
	// head->next->next->next = generateNewNode (3);
	// head->next->next->next->next = generateNewNode (1);

	ListNode* head2 = generateNewNode (5);
	// head2->next = generateNewNode (6);
	// head2->next->next = generateNewNode (4);
	// head2->next->next->next = generateNewNode (2);
	// head2->next->next->next->next = generateNewNode (1);

	ListNode* thisOne = head;
	cout << "head1:" << endl;
	while (thisOne != NULL) {
		cout << thisOne->val << " ";
		thisOne = thisOne->next;
	}
	cout << endl;
	thisOne = head2;
	cout << "head2:" << endl;
	while (thisOne != NULL) {
		cout << thisOne->val << " ";
		thisOne = thisOne->next;
	}
	cout << endl;
	thisOne = addTwoNumbers(head, head2);
	cout << "output:" << endl;
	while (thisOne != NULL) {
		cout << thisOne->val << " ";
		thisOne = thisOne->next;
	}
	cout << endl;
	return 0;
}




