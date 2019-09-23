class Solution {
public:
    int sqNo(int x, int y) {
        int col;
        if(y<=2) col = 0;
        else if(y>2&&y<=5) col = 1;
        else col = 2;
        
        if(x<=2) return col;
        else if(x>2&&x<=5) return 3 + col;
        else return 6 + col;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> sq(9);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                int val = board[i][j];
                auto itr = rows[i].find(val);
                auto itc = cols[j].find(val);
                int sqNumber = sqNo(i, j);
                auto its = sq[sqNumber].find(val);
                if(itr == rows[i].end()) rows[i].insert(val);
                else return false;
                if(itc == cols[j].end()) cols[j].insert(val);
                else return false;
                if(its == sq[sqNumber].end()) sq[sqNumber].insert(val);
                else return false;
            }
        }
        return true;
    }
};
