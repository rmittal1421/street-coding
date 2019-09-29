class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(!size) return 0;
        vector<int> maxL(size), maxR(size);
        
        int m = height[0];
        maxL[0] = m;
        for(int i = 1; i < size; i++) {
            if(height[i] >= m) {
                maxL[i] = height[i];
                m = height[i];
            } else {
                maxL[i] = m;
            }
        }
        
        maxR[size - 1] = height[size - 1];
        m = height[size - 1];
        for(int i = size - 2; i >= 0; i--) {
            if(height[i] >= m) {
                maxR[i] = height[i];
                m = height[i];
            } else {
                maxR[i] = m;
            }
        }
        
        for(int i = 0; i < size; i++) {
            cout << maxL[i] << " " << maxR[i] << endl;
        }
        
        int total = 0;
        for(int i = 0; i < size; i++) {
            total += max(min(maxL[i], maxR[i]) - height[i], 0);
        }
        return total;
    }
};
