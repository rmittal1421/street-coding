class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int origR = nums.size();
        if (origR == 0) return nums;
        
        int origC = nums[0].size();
        if (origC == 0 || (r*c != origR*origC)) return nums;
        
        vector<vector<int>> reshape(r);
        int cr = 0;
        int cc = 0;
        for(auto vec: nums) {
            for(int i : vec) {
                if (cc == c) {
                    cc = 0;
                    cr++;
                }
                reshape[cr].push_back(i);
                cc++;
            }
        }
        return reshape;
    }
};
