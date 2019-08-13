class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int s = 0, l = A.size() - 1;
        
        while(s < l) {
            int m = (s + l) / 2;
            if(A[m] < A[m + 1]) s = m + 1;
            else l = m;
        }
        return s;
    }
};
