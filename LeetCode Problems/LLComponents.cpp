#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

int numComponents (ListNode* head, vector<int>& G) {
	ListNode* current = head;
	int count = 0;

	if (head == NULL) return count;

	int compSize = 0;
	while (current != NULL) {
		if (std::find(G.begin(), G.end(), current->val) != G.end()) {
			compSize++;
		} else {
			if (compSize != 0) {
				count++;
				compSize = 0;
			}
		}
		current = current->next;
	}
	if (compSize!=0) count++;
	return count;
}

ListNode* generateNewNode (int value) {
	ListNode* newNode = new ListNode (value);
	return newNode;
}

int main () {
	vector<int> G;
	// G.push_back(0);
	// G.push_back(1);
	G.push_back(4);
	// G.push_back(3);
	ListNode* head = generateNewNode (3);
	head->next = generateNewNode (4);
	head->next->next = generateNewNode (0);
	head->next->next->next = generateNewNode (2);
	head->next->next->next->next = generateNewNode (1);
	ListNode* thisOne = head;
	cout << "Before" << endl;
	while (thisOne != NULL) {
		cout << thisOne->val << endl;
		thisOne = thisOne->next;
	}
	cout << "No of comps are: " << numComponents(head, G) << endl;
	return 0;
}




