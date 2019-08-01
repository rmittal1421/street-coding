class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r,c;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                //It is sure that there is one rook
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        
        int count = 0;
        for(int k = c + 1; k < board[r].size(); k++) {
            if (board[r][k] == 'p') {
                count++;
                break;
            } else if (board[r][k] == 'B') {
                break;
            }
        }
        for(int k = c - 1; k >= 0; k--) {
            if (board[r][k] == 'p') {
                count++;
                break;
            } else if (board[r][k] == 'B') {
                break;
            }
        }
        for(int k = r + 1; k < board.size(); k++) {
            if (board[k][c] == 'p') {
                count++;
                break;
            } else if (board[k][c] == 'B') {
                break;
            }
        }
        for(int k = r - 1; k >= 0; k--) {
            if (board[k][c] == 'p') {
                count++;
                break;
            } else if (board[k][c] == 'B') {
                break;
            }
        }
        
        return count;    
    }
};
