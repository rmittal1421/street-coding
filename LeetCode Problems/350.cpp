class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        unordered_map<int, int> map;
        
        for(int i : nums1) {
            if(map.find(i) == map.end()) {
                map[i] = 1;
            } else {
                map[i]++;
            }
        }
        
        vector<int> result;
        for(int j : nums2) {
            if(map.find(j) != map.end()) {
                if(map.find(j)->second > 0) {
                    result.push_back(j);
                    map[j]--;
                }
            }
        }
        return result;
    }
};
