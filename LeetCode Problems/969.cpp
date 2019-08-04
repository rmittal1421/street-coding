class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> B = A;
        sort(B.begin(), B.end());
        unordered_map<int, int> map;
        for(int i = 0; i < A.size(); i++) {
            map[A[i]] = i;
        }
        
        vector<int> ans;
        for(int i = 0; i < A.size(); i++) {
            map[A[i]] = i;
        }
        
        for(int i = B.size() - 1; i >= 0; i--) {
            int actualIndex = map[B[i]];
            if(actualIndex != i) {
                if(actualIndex != 0) {
                    reverse(A.begin(), A.begin() + actualIndex + 1);
                    ans.push_back(actualIndex + 1);
                }
                ans.push_back(i + 1);
                reverse(A.begin(), A.begin() + i + 1);
                for (int i = 0; i < A.size(); i++) {
                    map[A[i]] = i;
                }
            }
        }
        return ans;
    }
};
