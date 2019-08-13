class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        vector<int> values;
        values.push_back(0);
        for(double i = 1; i < n; i++) {
            values.push_back(i + values[i-1]);
            if(i <= n && (i+1) > (n - values[i])) return i;
        }
        return 0;
    }
};
