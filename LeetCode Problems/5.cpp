class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return s;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for(int i = 0; i < s.size(); i++) 
            dp[i][i] = true;
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = s.size() - 1; j >= 0; j--) {
                if(i == j) dp[i][j] = true;
                else if(i > j) dp[i][j] = false;
                else if(j == i + 1) dp[i][j] = (s[i] == s[j]);
                else {
                    dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
                }
            }
        }
        
        int start = 0, end = 0, max = 0;
    
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < s.size(); j++) {
                if(dp[i][j] && (j - i) > max) {
                    max = j - i;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, max + 1);
    }
};
