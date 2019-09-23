class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return s;
        reverse(s.begin(), s.end());
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while(getline(ss, token, ' ')) {
            if(token == "") continue;
            reverse(token.begin(), token.end());
            tokens.push_back(token);
        }
        s = "";
        for(int i = 0; i < tokens.size(); i++) {
            s += tokens[i];
            if(i < tokens.size() - 1) s += " ";
        }
        return s;
    }
};
