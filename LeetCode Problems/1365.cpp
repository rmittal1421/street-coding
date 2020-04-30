class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int x: nums) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > x) {
                    result[i]++;
                }
            }
        }
        return result;
    }
};