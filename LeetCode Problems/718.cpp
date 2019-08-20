class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if(A[i] == B[j]) dp[i][j] = 1;
            }
        }
        
        int largest = 0;
        for(int i = 1; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if(dp[i][j] != 0) {
                    if(i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] += dp[i-1][j-1];
                    }
                    if(dp[i][j] > largest) largest = dp[i][j];
                }
            }
        }
        
        return largest;
    }
};
