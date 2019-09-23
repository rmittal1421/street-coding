class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m + n);
        int a = 0, b = 0;
        
        int counter = 0;
        
        while(a < m && b < n) {
            if(nums1[a] <= nums2[b]) {
                ans[counter] = nums1[a];
                a++;
            } else {
                ans[counter] = nums2[b];
                b++;
            }
            counter++;
        }
        
        while(a<m) {
            ans[counter] = nums1[a];
            a++;
            counter++;
        }
        while(b<n) {
            ans[counter] = nums2[b];
            b++;
            counter++;
        }
        
        for(int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
        
        return;
    }
};
