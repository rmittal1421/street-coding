class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int size=A.size();
        if(size<=1) return A;
        int fix = size-1;
        bool found = false;
        for(int i=size-2;i>=0;i--) {
            if(A[i]>A[fix]) {
                fix=i;
                found = true;
                break;
            }
            fix--;
        }
        if (!found) return A;
        int smallest = fix+1;
        for(int i=fix+2;i<size;i++) {
            if(A[i]>A[smallest] && A[i]<A[fix]) {
                smallest = i;
            } 
        }
        int temp=A[fix];
        A[fix]=A[smallest];
        A[smallest]=temp;
        return A;
    }
};
