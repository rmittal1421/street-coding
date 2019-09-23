class Solution {
public:
    string reverseWords(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        
        vector<string> reversed;
        stringstream tokens(r);
        string token;
        while(getline(tokens, token, ' '))
            reversed.push_back(token);
        reverse(reversed.begin(), reversed.end());
        string ans = "";
        for(int i = 0; i < reversed.size(); i++) {
            ans += reversed[i];
            if(i < reversed.size() - 1) ans += " ";
        }
        return ans;
    }
};
