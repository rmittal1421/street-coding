class Solution {
public:
    int count(string s) {
        int count = 0;
        char c = 'z' + 1;
        for(char ch : s) {
            if(ch < c) {
                c = ch;
                count = 1;
            } else if (ch == c) count++;
        }
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> counts(words.size());
        int i = 0;
        for(string word : words) {
            counts[i] = count(word);
            i++;
        }
        
        int j = 0;
        vector<int> ans(queries.size());
        for(string word : queries) {
            int co = 0;
            int c = count(word);
            for(int i : counts) {
                if(c < i) co++;
            }
            ans[j] = co;
            j++;
        }
        return ans;
    }
};