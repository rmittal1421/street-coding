class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> heights2 = heights;
        std::sort(heights.begin(), heights.end());
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != heights2[i])
                count++;
        }
        return count;
    }
};
