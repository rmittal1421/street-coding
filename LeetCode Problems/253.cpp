class Solution {
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int k = 0; //Number of classrooms
        
        sort(intervals.begin(), intervals.end(), sortcol);
        
        priority_queue<int, vector<int>, std::greater<int>> p;
        for(int i = 0; i < intervals.size(); i++) {
            if(p.empty()) {
                k++;
                p.push(intervals[i][1]);
            } else {
                int min = p.top();
                if(min <= intervals[i][0]) p.pop();
                else k++;
                 p.push(intervals[i][1]);
            }
        }
        
        return k;
    }
};
