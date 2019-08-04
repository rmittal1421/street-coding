class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int aSum = 0, bSum = 0;
        for(int i : A) {
            aSum += i;
        }
        for(int i : B) {
            bSum += i;
        }
        
        int diffToFind = (aSum-bSum)/2;

        unordered_map<int, int> map;
        for(int i : A) {
            map[i-diffToFind] = i;
        }
        
        for (int j : B) {
            if(map.find(j) != map.end()) {
                return vector<int> {map[j], j};
            }
        }
        return vector<int>{-1,-1};
    }
};
