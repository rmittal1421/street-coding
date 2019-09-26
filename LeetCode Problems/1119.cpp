class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') return true;
        else return false;
    }
    
    string removeVowels(string S) {
        queue<char> q;
        for(char c : S) {
            if(!isVowel(c)) q.push(c);
        }
        S = "";
        while(!q.empty()) {
            S += q.front();
            q.pop();
        }
        return S;
    }
};
