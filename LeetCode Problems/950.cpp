class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> actual = deck;
        sort(actual.begin(), actual.end());
        
        unordered_map<int, int> map;
        queue<int> q;
        for(int i = 0; i < deck.size(); i++) {
            map[deck[i]] = i;
            q.push(deck[i]);
        }
        
        int i = 0;
        while(!q.empty()) {
            deck[i] = q.front();
            i++;
            q.pop();
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        
        vector<int> ans(deck.size());
        for(int i = 0; i < actual.size(); i++) {
            ans[map[deck[i]]] = actual[i]; 
        }
        return ans;
    }
};
