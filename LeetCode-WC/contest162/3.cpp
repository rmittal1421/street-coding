class Solution {
public:
    vector<int> f{0, -1, 0, 1};
    vector<int> s{-1, 0, 1, 0};
    
    void traverse(int i, int j, vector<vector<int>>& grid, int& corner) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            corner++;
            return;
        }
        
        if(grid[i][j] == 1) return;
        grid[i][j] = 1;
        
        for(int k = 0; k < 4; k++) 
            traverse(i + f[k], j + s[k], grid, corner);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0, corner = 0;
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    corner = 0;
                    traverse(i, j, grid, corner);
                    if(corner == 0) result++;
                }
            }
        }
        
        return result;
    }
};