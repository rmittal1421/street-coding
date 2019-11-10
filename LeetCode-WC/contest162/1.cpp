class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(auto p : indices) {
            for(int i = 0; i < m; i++) mat[p[0]][i]++;
            for(int i = 0; i < n; i++) mat[i][p[1]]++;
        }
        int ans = 0;
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[i].size(); ++j) {
                if(mat[i][j]%2 != 0) ans++;
                // cout<<mat[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};