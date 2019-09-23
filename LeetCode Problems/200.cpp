class Solution {
public:
    vector<int> f{-1, 0, 1, 0};
    vector<int> s{0, -1, 0, 1};
    
    bool includes(const vector<vector<char>> &grid, int i, int j) {
        if((i < grid.size()) && (i >= 0) && (j < grid[0].size()) && (j >= 0)) return true;
        else return false;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] != '1') return;
        grid[i][j] += 1;
        for(int a = 0; a < f.size(); a++) {
            int x = i + f[a], y = j + s[a];
            if(includes(grid, x, y) && grid[x][y] == '1') dfs(grid, x, y);
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int count = 0;
        int grs = grid.size(), gcs = grid[0].size();
        
        for(int i = 0; i < grs; i++) {
            for(int j = 0; j < gcs; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};      
