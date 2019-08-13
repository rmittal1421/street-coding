class Solution {
public:
    int binarySearch(vector<int>& A, int start, int last) {
        if(last < start) return -1;
        else if(last == start) return start;
        else {
            int middle = (last + start) / 2;
            int middleElem = A[middle];
            int leftToMiddle = A[middle - 1];
            int rightToMiddle = A[middle + 1];
            if(middleElem > leftToMiddle && middleElem > rightToMiddle) {
                return middle;
            } else {
                return (middleElem < leftToMiddle) ? binarySearch(A, start, middle) : binarySearch(A, middle + 1, last);
            }
        }
    }
    
    int peakIndexInMountainArray(vector<int>& A) {
        return binarySearch(A, 0, A.size() - 1);
    }
};
