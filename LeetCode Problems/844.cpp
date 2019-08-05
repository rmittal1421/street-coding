class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1, s2;
        for(int i = 0; i < S.size(); i++) {
            if(!s1.empty() && S[i] == '#') s1.pop();
            else if (S[i] != '#') s1.push(S[i]);
        }
        for(int i = 0; i < T.size(); i++) {
            if(!s2.empty() && T[i] == '#') s2.pop();
            else if (T[i] != '#') s2.push(T[i]);
        }
        
        if(s1.size() != s2.size()) {
            return false;
        } else {
            while(!s1.empty()) {
                char c1 = s1.top();
                char c2 = s2.top();
                if (c1 != c2) {
                    return false;
                } else {
                    s1.pop();
                    s2.pop();
                }
            }
            return true;
        }
    }
};
