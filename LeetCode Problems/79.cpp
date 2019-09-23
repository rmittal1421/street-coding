class Solution {
public:
    vector<int> f{-1, 0, 1, 0};
    vector<int> s{0, -1, 0, 1};
    
    bool includes(vector<vector<char>> &board, int x, int y) {
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
        else return false;
    }
    
    bool dfs(vector<vector<char>> &board, string& word, vector<vector<bool>> &used, int curr, int x, int y) {
        if(used[x][y]) return false;
        used[x][y] = true;
        if(curr >= word.size()) return true;
        bool foundInRecc = false;
        for(int i = 0; i < f.size(); i++) {
            int a = x + f[i], b = y + s[i];
            if(includes(board, a, b)) {
                if(board[a][b] == word[curr]) {
                    foundInRecc = dfs(board, word, used, curr + 1, a, b);
                    if(foundInRecc) return true;
                }
            }
        }
        used[x][y] = false;
        return foundInRecc;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        if(word == "") return false;
        bool found = false;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> used(board.size(), vector<bool>(board[0].size()));
                if(board[i][j] == word[0]) {
                    found  = dfs(board, word, used, 1, i, j);
                    if(found) return true;
                }
            }
        }
        return found;
    }
};
