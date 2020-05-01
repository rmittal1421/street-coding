class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> overall(101);
        for(int x: nums) overall[x]++;
        for(int i = 1; i < overall.size(); i++) overall[i] += overall[i-1];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) nums[i] = overall[nums[i] - 1];
        }
        return nums;
    }
};