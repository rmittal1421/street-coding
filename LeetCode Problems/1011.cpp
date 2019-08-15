class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int min = weights[0], max = 0;
        for(int i : weights) {
            if(i > min) min = i;
            max += i;
        }
        
        int ws = weights.size();
        while(min < max) {
            int counter = D;
            int bottle = min;
            int i = 0;
            while(counter > 0 && i < ws) {
                int w = weights[i];
                if((bottle - w) >= 0) {
                    bottle -= w;
                    i++;
                } else {
                    bottle = min;
                    counter--;
                }
            }
            
            if(i == ws) return min;
            else {
                min++;
            }
        }
        return max;
    }
};
