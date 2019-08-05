class Solution {
public:
    string removeOuterParentheses(string S) {
        int start, last;
        queue<char> q;
        string ans = "";
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '(') {
                if(q.empty()) start = i;
                q.push(S[i]);
            } else {
                if(q.size() == 1) {
                    last = i;
                    ans += S.substr(start + 1, last - start - 1);
                }
                q.pop();
            }
        }
        return ans;
    }
};
