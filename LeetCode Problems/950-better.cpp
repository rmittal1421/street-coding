class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        for(int i = 0; i < deck.size(); i++) {
            q.push(i);
        }
        
        vector<int> ans(deck.size());
        sort(deck.begin(), deck.end());
        
        for(int i : deck) {
            ans[q.front()] = i;
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
