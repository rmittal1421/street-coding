class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start == destination) return 0;
        int init = start;
        int clock = 0, anti = 0;
        bool clockb = true, antib = false;
        for(int i = start;; i++) {
            int first = distance[start];
            start = (start+1 == distance.size()) ? 0 : start + 1;
            if(clockb) clock += first;
            else anti += first;
            if(start == destination) {
                clockb = false;
                antib = true;
            } else if (start == init) break;
        }
        
        return min(clock, anti);
    }
};
