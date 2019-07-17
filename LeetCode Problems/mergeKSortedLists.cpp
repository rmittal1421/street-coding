#include <stdc++.h>
#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <functional> 

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam=false)
	{reverse=revparam;}
	bool operator() (const ListNode* lhs, const ListNode* rhs) const
	{
		if (reverse) return (lhs->val>rhs->val);
		else return (lhs->val<rhs->val);
	}
}; 

typedef std::priority_queue<ListNode*,std::vector<ListNode*>,mycomparison> pqComp;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* newHead = NULL;
    ListNode* now = NULL;
    
    pqComp pq(mycomparison(true));

    for (int i = 0; i < lists.size(); ++i) {
    	pq.push (lists[i]);
    	lists[i] = lists[i]->next;
    }
    
    while (!pq.empty()) {
        ListNode* topPQ = pq.top();
        if (topPQ->next) pq.push (topPQ->next);
        pq.pop();
        if (!newHead) {
            newHead = topPQ;
            now = newHead;
        } else {
            now->next = topPQ;
            now = topPQ;
        }
    }
    return newHead;
}

int main () {
	// pqComp pq (mycomparison(true));
	ListNode* a1 = new ListNode (1);
	a1->next = new ListNode (4);
	a1->next->next = new ListNode (5);

	ListNode* a2 = new ListNode (1);
	a2->next = new ListNode (3);
	a2->next->next = new ListNode (4);

	ListNode* a3 = new ListNode (2);
	a3->next = new ListNode (7);

	std::vector<ListNode*> v;
	v.push_back (a1);
	v.push_back (a2);
	v.push_back (a3);

	for (int i = 0; i < v.size(); i++) {
		ListNode* current =  v[i];
		while (current) cout << current->val << " ", current = current->next;
		cout << endl;
	}

	ListNode* newHead = mergeKLists (v);
	// a1->next->next = new ListNode (5);

	// ListNode* a2 = new ListNode (2);
	// ListNode* a3 = new ListNode (3);
	// ListNode* a4 = new ListNode (4);
	// ListNode* a5 = new ListNode (5);

	// pq.push (a3);
	// pq.push (a2);
	// pq.push (a4);
	// pq.push (a5);
	// pq.push (a1);

	// cout << pq.top()->val << endl;
	// cout << endl;
	// pq.pop();	

	// a1->val = 10;
	// pq.push (a1);

	// while (!pq.empty()) {
	// 	cout << pq.top()->val << endl;
	// 	pq.pop();
	// }

	cout <<"Got stuck in the function" << endl;

	while (newHead) {
		cout << newHead->val << endl;
		newHead = newHead->next;
	}
	return 0;
}






