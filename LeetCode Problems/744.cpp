class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters[letters.size() - 1]) return letters[0];
        int s = 0, l = letters.size() - 1;
        while(s < l) {
            int m = (s+l)/2;
            if(target >= letters[m]) s = m + 1;
            else l = m;
        }
        return letters[s];
    }
};
