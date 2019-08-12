/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
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
            if (lists[i]) pq.push (lists[i]);
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
};
