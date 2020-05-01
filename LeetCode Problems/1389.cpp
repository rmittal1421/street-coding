class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int size = nums.size();
        vector<int> v;
        for(int i = 0; i < size; i++) {
            v.insert(v.begin()+index[i],nums[i]);
        }
        return v;
    }
};