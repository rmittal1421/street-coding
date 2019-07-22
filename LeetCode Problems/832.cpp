class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            int s = A[i].size();
            for (int j = 0; j < s/2; j++) {
                int temp = A[i][j];
                A[i][j] = 1- A[i][abs(s-1-j)];
                A[i][abs(s-1-j)] = 1 - temp;
            }
            if (s%2!=0) A[i][s/2] = 1 - A[i][s/2];
        }
        
        return A;
    }
};