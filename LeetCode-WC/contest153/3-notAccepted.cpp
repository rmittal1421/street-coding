class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), INT_MIN));
        vector<vector<int>> min(arr.size(), vector<int>(arr.size(), 0));
        
        for(int i = 0; i < arr.size(); i++) {
            dp[i][i] = arr[i];
            if(arr[i] < 0) min[i][i] = arr[i];
        }
        
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                dp[i][j] = dp[i][j-1] + arr[j];
                if(min[i][j-1] > arr[j]) min[i][j] = arr[j];
                else min[i][j] = min[i][j-1];
            }
        }
        
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                dp[i][j] += -1 * min[i][j];
            }
        }
        
        int max = INT_MIN;
        for(auto i : dp) {
            for(int j : i) {
                if(max < j) max = j;
            }
        }
        
        return max;
    }
};
