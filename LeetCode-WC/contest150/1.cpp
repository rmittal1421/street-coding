class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> map;
        for(char c : chars) {
            if(map.find(c) == map.end()) {
                map[c] = 1;
            } else {
                map[c]++;
            }
        }
        
        int ans = 0;
        for(string s : words) {
            vector<int> fre(26);
            bool canForm = true;
            for(char c : s) {
                int count = ++fre[c-'a'];
                if(map.find(c) == map.end()) {
                    canForm = false;
                    break;
                }
                else {
                    if(map.find(c)->second < count) {
                        canForm = false;
                        break;
                    }
                }
            }
            if(canForm) ans += s.size();
        }
        return ans;
    }
};
