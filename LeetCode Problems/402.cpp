class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> s;
        if(num == "" || k >= num.size()) return "0";
        s.push_back(num[0]);
        
        int toRemove = 0, counter = 1;
        for(int i = 1; i < num.size(); i++) {
            if(!s.empty() && (k != 0) && (num[i] < s.back())) {
                s.pop_back();
                k--;
                i--;
            } else {
                s.push_back(num[i]);
            }
        }
        
        while(k != 0) s.pop_back(), k--;
         
        string ans = "";
        while(!s.empty() && s.front() == '0') s.pop_front();
        while(!s.empty()) ans += s.front(), s.pop_front();
        if(ans == "") ans = "0";
        return ans;
    }
};
