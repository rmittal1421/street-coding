class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int currentInd = 0;
        int fix = 0;
        for(int i = 0; i<arr2.size(); i++) {
            while (currentInd<arr1.size()) {
                if (arr1[currentInd] == arr2[i]) {
                    int temp = arr1[currentInd];
                    arr1[currentInd]=arr1[fix];
                    arr1[fix]=temp;
                    fix++;
                }
                currentInd++;
            }
            currentInd = fix;
        }
        sort(arr1.begin()+fix, arr1.end());
        return arr1;
    }
};
