#include<iostream>
#include <string>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	/*
	This method is a method which contains fast and slow runner idea.
	Try the same question with hash map.
	But for the hash map, the complexity will be O(n) since we will be adding 
	all the nodes in the hash map in the worst case scenario.
	*/
	if (!head) return false;
	if (!head->next) return false;
	if (head->next == head) return true;

	ListNode* fastMoving = head->next;
	ListNode* slowMoving = head;

	while (fastMoving != NULL) {
		if (fastMoving->next != slowMoving) {
			if (fastMoving->next != NULL) {
				if (fastMoving->next->next != slowMoving) {
					fastMoving = fastMoving->next->next;
					slowMoving = slowMoving->next;
				}
				else return true;
			} else return false;
		} else return true;
	}
	return false;

}





