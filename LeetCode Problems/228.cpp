class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> map;
        if (nums.size() == 0) return map;
        int ci = nums[0];
        int lc = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] != 1+lc) {
                map.push_back(to_string(ci) + ((ci != lc) ? "->" + to_string(lc) : ""));
                ci = nums[i];  
            } 
            lc = nums[i]; 
        }
        
        if (lc == nums[nums.size() - 1]) {
                map.push_back(to_string(ci) + ((ci != lc) ? "->" + to_string(lc) : ""));
            }
        return map;
    }
};