class Solution {
public:
    int checkIndex(int i, int j, vector<vector<int>> &grid) {
        if(!((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[i].size()))) {
            return 0;
        }
        return 1;
    } 
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int &area) {
        if(visited[i][j] == 1) return;
        visited[i][j] = 1;
        if(grid[i][j] == 0) {      
            return;
        }
        area++;
        
        if (checkIndex(i+1, j, grid) && (visited[i+1][j] == 0)) dfs(i+1, j, grid, visited, area);
        if (checkIndex(i, j-1, grid) && (visited[i][j-1] == 0)) dfs(i, j-1, grid, visited, area);
        if (checkIndex(i-1, j, grid) && (visited[i-1][j] == 0)) dfs(i-1, j, grid, visited, area);
        if (checkIndex(i, j+1, grid) && (visited[i][j+1] == 0)) dfs(i, j+1, grid, visited, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                int area = 0;
                if(grid[i][j] != 0) dfs(i, j, grid, visited, area);
                if (area > maxArea) maxArea = area;
            }
        }
        
        return maxArea;
    }
};
