class Solution {
public:
    int searchBinary (vector<int>& nums, int target, int left, int right) {
        if (left>right) return -1;
        int middle = (left+right)/2;
        bool c1 = target>=nums[left];
        bool c2 = target < nums[middle];
        bool c3 = target <= nums[right];
        
        bool c5 = (nums[middle]<=nums[right]) ? !c2&&c3 : !c2||c3;
        bool c4 = (nums[left]<=nums[middle]) ? c1&&c2 : c1||c2;
        
        if (target == nums[middle]) return middle;
        else if (c4 || !c5) {
            return searchBinary (nums, target, left, middle-1);
        } else {
            return searchBinary (nums, target, middle+1, right);
        }
    }
    
    
    int search(vector<int>& nums, int target) {
        return searchBinary (nums, target, 0, nums.size()-1);
    }
};