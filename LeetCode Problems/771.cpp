class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::set<char> s;
        for(char x: J) s.insert(x);
        int stones = 0;
        for(char x: S) {
            if(s.find(x) != s.end()) stones++;
        }
        return stones;
    }
};