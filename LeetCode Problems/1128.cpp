class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> match;
        for(vector<int> A : dominoes) {
            string key = (A[0]<=A[1]) ? to_string(A[0])+" "+to_string(A[1]) : to_string(A[1])+" "+to_string(A[0]);
            if(match.find(key) == match.end()) {
                match[key] = 1;
            } else {
                match[key] += 1;
            }
        }
        
        int result=0;
        for(auto it=match.begin(); it != match.end(); it++) {
            cout<<it->first<<" "<<it->second<<endl;
            result += it->second * (it->second - 1)/2;
        }
        return result;
    }
};
