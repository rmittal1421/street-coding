class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int size = colsum.size();
        vector<vector<int>> ans(2, vector<int>(size, 0));
        
        for(int i = 0; i < size; i++) {
            if(colsum[i] == 2) {
                if(upper == 0 || lower == 0) return vector<vector<int>>(0, vector<int>(0, 0));
                if(upper > 0) ans[0][i]++, upper--;
                if(lower > 0) ans[1][i]++, lower--;
            }
        }
        for(int i = 0; i < size; i++) {
            if(colsum[i] == 1) {
                if(upper > 0) ans[0][i]++, upper--;
                else if(lower > 0) ans[1][i]++, lower--;
                else return vector<vector<int>>(0, vector<int>(0, 0));
            }
        }
        if(upper != 0 || lower != 0) return vector<vector<int>>(0, vector<int>(0, 0));
        return ans;
    }
};