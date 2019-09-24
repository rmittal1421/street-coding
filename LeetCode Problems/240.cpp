class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        else if(matrix[0].size() == 0) return false;
        else if(target < matrix[0][0]) return false;
        else if(target > matrix[matrix.size()-1][matrix[0].size()-1]) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0, col = n - 1;
        
        while(row>=0 && row < m && col>=0 && col < n) {
            int val = matrix[row][col];
            if(val == target) return true;
            else if(val > target) col--;
            else row++;
        }
        return false;
    }
};
