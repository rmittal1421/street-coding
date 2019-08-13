class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1) return false;
        else if(num == 1) return true;
        int s = 0, l = num/2;
        
        while(s < l) {
            int m = (s+l)/2;
            if(m < num/m) s = m+1;
            else l = m;
        }
        
        return (l == num/l && num%l == 0);
    }
};
