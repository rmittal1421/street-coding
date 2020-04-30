class Solution {
public:
    string defangIPaddr(string address) {
        std::queue<char> q;
        for(char x: address) {
            if(x == '.') q.push('[');
            q.push(x);
            if(x == '.') q.push(']');
        }
        string ans = "";
        while(!q.empty()) {
            ans += q.front();
            q.pop();
        }
        return ans;
    }
};